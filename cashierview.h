#ifndef CASHIERVIEW_H
#define CASHIERVIEW_H
#include "tablecontroller.h"
#include <QDialog>
#include "QFile"
#include "tableinfo.h"

namespace Ui {
    class cashierView;
}

class cashierView : public QDialog
{
    Q_OBJECT

public:
    explicit cashierView(QWidget *parent = 0);
    ~cashierView();
    void setController(TableController *a);
    void writeData();
    void readData();

private slots:
    void on_PayButton_clicked();

    void on_RefreashButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::cashierView *ui;
    TableController *tc;
    QString money;
    QString tableID;
    QString tableType;
    TableInfo ti;


};

#endif // CASHIERVIEW_H
