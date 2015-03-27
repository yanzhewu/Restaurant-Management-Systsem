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
        QString t= "С��λ";
        QString n= QString::number(tc->small[i].returnTableID(),10);
    QString m = QString::number(tc->small[i].customerID,10);
    QString time = tc->small[i].isAva()?"��":"��";

    int c=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(c);

    ui->tableWidget->setItem(c,0,new QTableWidgetItem(t));
    ui->tableWidget->setItem(c,1,new QTableWidgetItem(n));
    ui->tableWidget->setItem(c,2,new QTableWidgetItem(m));
    ui->tableWidget->setItem(c,3,new QTableWidgetItem(time));
    }

    for(int i=0;i<10;i++){
        QString t= "�в�λ";
        QString n= QString::number(tc->medium[i].returnTableID(),10);
    QString m = QString::number(tc->medium[i].customerID,10);
    QString time = tc->medium[i].isAva()?"��":"��";


    int c=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(c);

    ui->tableWidget->setItem(c,0,new QTableWidgetItem(t));
    ui->tableWidget->setItem(c,1,new QTableWidgetItem(n));
    ui->tableWidget->setItem(c,2,new QTableWidgetItem(m));
    ui->tableWidget->setItem(c,3,new QTableWidgetItem(time));
    }

    for(int i=0;i<5;i++){
        QString t= "���λ";
        QString n= QString::number(tc->large[i].returnTableID(),10);
    QString m = QString::number(tc->large[i].customerID,10);
    QString time = tc->large[i].isAva()?"��":"��";


    int c=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(c);

    ui->tableWidget->setItem(c,0,new QTableWidgetItem(t));
    ui->tableWidget->setItem(c,1,new QTableWidgetItem(n));
    ui->tableWidget->setItem(c,2,new QTableWidgetItem(m));
    ui->tableWidget->setItem(c,3,new QTableWidgetItem(time));
    }
}
