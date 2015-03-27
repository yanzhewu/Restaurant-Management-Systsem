#include "login.h"
#include "ui_login.h"
#include "tablecontroller.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)

{
    ui->setupUi(this);
    ui->PasswordEdit->setEchoMode(QLineEdit::Password);
    customerNum = 0;

}

Login::~Login()
{
    delete ui;
}

void Login::on_LoginButton_clicked()
{       if(ui->NameEdit->text()==tr("wuw10")&&ui->PasswordEdit->text()==tr("12345")&&ui->TypeBox->currentIndex()==1){
        //判断用户名和密码是否正确

        ca.setController(tmp);
        ca.show();
    }
    else if(ui->NameEdit->text()!=NULL&&ui->TypeBox->currentIndex()==0){
        state = 1;
        customerNum++;
        Customer tmc = Customer(customerNum,this->returnName());
        list.push_back(tmc);
        cv.setController(tmp,tmc);
        cv.show();
        }
        else{
        QMessageBox::warning(this,tr("Warning!"),tr("Username or Password error!"),QMessageBox::Yes);
}
}

QString Login::returnName(){
    return ui->NameEdit->text();
}

void Login::setController(TableController *a){
    tmp = a;
}
