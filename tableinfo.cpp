#include "tableinfo.h"
#include "ui_tableinfo.h"

TableInfo::TableInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableInfo)
{
    ui->setupUi(this);
}

TableInfo::~TableInfo()
{
    delete ui;
}

void TableInfo::setcontroller(TableController *a){
    tc =a;

    for(int i=0;i<15;i++){
        QString t= "小餐位";
        QString n= QString::number(tc->small[i].returnTableID(),10);
    QString m = QString::number(tc->small[i].customerID,10);
    QString time = tc->small[i].isAva()?"是":"否";

    int c=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(c);

    ui->tableWidget->setItem(c,0,new QTableWidgetItem(t));
    ui->tableWidget->setItem(c,1,new QTableWidgetItem(n));
    ui->tableWidget->setItem(c,2,new QTableWidgetItem(m));
    ui->tableWidget->setItem(c,3,new QTableWidgetItem(time));
    }

    for(int i=0;i<10;i++){
        QString t= "中餐位";
        QString n= QString::number(tc->medium[i].returnTableID(),10);
    QString m = QString::number(tc->medium[i].customerID,10);
    QString time = tc->medium[i].isAva()?"是":"否";


    int c=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(c);

    ui->tableWidget->setItem(c,0,new QTableWidgetItem(t));
    ui->tableWidget->setItem(c,1,new QTableWidgetItem(n));
    ui->tableWidget->setItem(c,2,new QTableWidgetItem(m));
    ui->tableWidget->setItem(c,3,new QTableWidgetItem(time));
    }

    for(int i=0;i<5;i++){
        QString t= "打餐位";
        QString n= QString::number(tc->large[i].returnTableID(),10);
    QString m = QString::number(tc->large[i].customerID,10);
    QString time = tc->large[i].isAva()?"是":"否";


    int c=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(c);

    ui->tableWidget->setItem(c,0,new QTableWidgetItem(t));
    ui->tableWidget->setItem(c,1,new QTableWidgetItem(n));
    ui->tableWidget->setItem(c,2,new QTableWidgetItem(m));
    ui->tableWidget->setItem(c,3,new QTableWidgetItem(time));
    }
}
