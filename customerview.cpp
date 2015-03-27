#include "customerview.h"
#include "ui_customerview.h"

customerView::customerView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerView)

{
    ui->setupUi(this);
}

customerView::~customerView()
{
    delete ui;
}

void customerView::setController(TableController *a, Customer b){
    tb = a;
    c = b;
    ui->Name->setText(c.getName());
    QString str = QString::number(c.getID(),10);
    ui->ID->setText(str);
    ui->People->setText("目前您还没有加入排队！");
    ui->People->setText("0");
    ui->Num->setText("目前还没有桌号！");
    refreash();

}

void customerView::refreash(){
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("0-4"));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("4-9"));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("9人以上"));



    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(tb->avaTableNum(1),10)));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(tb->avaTableNum(2),10)));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(tb->avaTableNum(3),10)));

    ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(tb->getCurrentCustomerID(1),10)));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem(QString::number(tb->getCurrentCustomerID(2),10)));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem(QString::number(tb->getCurrentCustomerID(3),10)));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(tb->getQueueNum(1),10)));
    ui->tableWidget->setItem(1,3,new QTableWidgetItem(QString::number(tb->getQueueNum(2),10)));
    ui->tableWidget->setItem(2,3,new QTableWidgetItem(QString::number(tb->getQueueNum(3),10)));

    ui->Small->setVisible(false);
    ui->Medium->setVisible(false);
    ui->Large->setVisible(false);
     ui->smallIn->setVisible(true);
      ui->mediumIn->setVisible(true);
      ui->largeIn->setVisible(true);

    if(tb->avaTableNum(1)==0){
        ui->smallIn->setVisible(false);
        ui->Small->setVisible(true);
    }
    if(tb->avaTableNum(2)==0){
        ui->mediumIn->setVisible(false);
        ui->Medium->setVisible(true);
    }
    if(tb->avaTableNum(3)==0){
        ui->largeIn->setVisible(false);
        ui->Large->setVisible(true);
    }

}

void customerView::on_Small_clicked()
{
    int i = tb->waitForTable(1,c);
    ui->People->setText(QString::number(i,10));
    ui->Num->setText(QString::number(i,10));
    refreash();

        ui->smallIn->setVisible(false);
        ui->Small->setVisible(false);

        ui->mediumIn->setVisible(false);
        ui->Medium->setVisible(false);

        ui->largeIn->setVisible(false);
        ui->Large->setVisible(false);
}


void customerView::on_smallIn_clicked()
{
    tb->allocateTable(1,c);
    ui->TableNum->setText(QString::number(c.tableID,10)+"  请直接入座！");

    refreash();

        ui->smallIn->setVisible(false);
        ui->Small->setVisible(false);

        ui->mediumIn->setVisible(false);
        ui->Medium->setVisible(false);

        ui->largeIn->setVisible(false);
        ui->Large->setVisible(false);

        ui->People->setText("0");
}

void customerView::on_mediumIn_clicked()
{
    tb->allocateTable(2,c);
    ui->TableNum->setText(QString::number(c.tableID,10)+"  请直接入座！");
    refreash();
    ui->smallIn->setVisible(false);
    ui->Small->setVisible(false);

    ui->mediumIn->setVisible(false);
    ui->Medium->setVisible(false);

    ui->largeIn->setVisible(false);
    ui->Large->setVisible(false);

    ui->People->setText("0");
}

void customerView::on_largeIn_clicked()
{
    tb->allocateTable(3,c);
    ui->TableNum->setText(QString::number(c.tableID,10)+"  请直接入座！");
    refreash();
    ui->smallIn->setVisible(false);
    ui->Small->setVisible(false);

    ui->mediumIn->setVisible(false);
    ui->Medium->setVisible(false);

    ui->largeIn->setVisible(false);
    ui->Large->setVisible(false);

    ui->People->setText("0");
}

void customerView::on_Medium_clicked()
{
    int i = tb->waitForTable(2,c);
    ui->People->setText(QString::number(i,10));
    ui->Num->setText(QString::number(i,10));
    refreash();

        ui->smallIn->setVisible(false);
        ui->Small->setVisible(false);

        ui->mediumIn->setVisible(false);
        ui->Medium->setVisible(false);

        ui->largeIn->setVisible(false);
        ui->Large->setVisible(false);
}

void customerView::on_Large_clicked()
{
    int i = tb->waitForTable(3,c);
    ui->People->setText(QString::number(i,10));
    ui->Num->setText(QString::number(i,10));
    refreash();
    ui->smallIn->setVisible(false);
    ui->Small->setVisible(false);

    ui->mediumIn->setVisible(false);
    ui->Medium->setVisible(false);

    ui->largeIn->setVisible(false);
    ui->Large->setVisible(false);

}

