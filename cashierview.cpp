#include "cashierview.h"
#include "ui_cashierview.h"
#include "QtGui"
#include "iostream"
#include <QDate>

using namespace::std;

cashierView::cashierView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cashierView)
{
    ui->setupUi(this);
    ui->ResultTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

cashierView::~cashierView()
{
    delete ui;
}

void cashierView::setController(TableController *a){
    tc = a;
}


void cashierView::on_PayButton_clicked()
{
    int type = ui->TypeBox->currentIndex();
    tableType = QString::number(type,10);
    tableID = ui->TableNumLine->text();
    money = ui->MoneyLine->text();
    if(type<200){
         tc->releaseTable(3,type);
        if(tc->getQueueNum(1)>0){
        int m = tc->outOfQueue(1);
        QMessageBox::warning(this,"通知","请"+QString::number(m,10)+"号顾客前来"+tableID+"号小桌就餐！",QMessageBox::Yes);
        }
        ui->TableNumLine->setText("");
        ui->MoneyLine->setText("");
    }
    else if(type >=200 && type <300){
            tc->releaseTable(2,type);
            if((tc->getQueueNum(2))>0){
                int m = tc->outOfQueue(2);
            QMessageBox::warning(this,"通知","请"+QString::number(m,10)+"号顾客前来"+tableID+"号小桌就餐！",QMessageBox::Yes);
            }
            ui->TableNumLine->setText("");
            ui->MoneyLine->setText("");
    }
    else if(type >= 300){
        tc->releaseTable(3,type);
        if((tc->getQueueNum(3))>0){
            int m = tc->outOfQueue(1);
        QMessageBox::warning(this,"通知","请"+QString::number(m,10)+"号顾客前来"+tableID+"号小桌就餐！",QMessageBox::Yes);
        }ui->TableNumLine->setText("");
        ui->MoneyLine->setText("");
}
    else{
        QMessageBox::warning(this,"警告","没有此桌号！",QMessageBox::Yes);
    }
    writeData();
    }

void cashierView::writeData(){
       QStringList lines;
       QFile file("sales.txt");
       if (file.open(QFile::ReadOnly))
       {
           QTextStream stream(&file);
           QString line;
           while (!stream.atEnd())
           {
               line = stream.readLine();
               if(line!=""){
               lines += line;
               }
           }
           file.close();
       }

    if (file.open(QFile::WriteOnly))
        {
            QTextStream stream(&file);
            QDate today(QDate::currentDate());
                    QString dayName=today.toString();
                    int i=0;
                    for (QStringList :: Iterator it = lines.begin(); it != lines.end();++it,i++){
                        stream <<lines[i]<<endl<<"\r\n";
                    }
                    stream << tableType <<" "<<tableID<<" "<<money<<" "<<dayName<<"\r\n";


                    file.close();


}
}

void cashierView::readData(){
    for(int i=ui->ResultTable->rowCount();i>=0;i--)
    ui->ResultTable->removeRow(0);

    QFile file("sales.txt");
    if (file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        QString line;
        while (!stream.atEnd() )
        {
            line = stream.readLine();
            if(line != ""){
            QString t= line.mid(0,1);
            QString n= line.mid(2,3);
            QString m = line.mid(6,3);
            QString time = line.mid(10,line.length()-10);

            int c=ui->ResultTable->rowCount();
            ui->ResultTable->insertRow(c);

            ui->ResultTable->setItem(c,0,new QTableWidgetItem(t));
            ui->ResultTable->setItem(c,1,new QTableWidgetItem(n));
            ui->ResultTable->setItem(c,2,new QTableWidgetItem(m));
            ui->ResultTable->setItem(c,3,new QTableWidgetItem(time));
            }
        }
        file.close();
    }
}

void cashierView::on_RefreashButton_clicked()
{
    readData();
}

void cashierView::on_pushButton_clicked()
{
    ti.setcontroller(tc);
    ti.show();
}
