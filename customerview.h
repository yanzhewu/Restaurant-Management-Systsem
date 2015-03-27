#ifndef CUSTOMERVIEW_H
#define CUSTOMERVIEW_H
#include "tablecontroller.h"
#include "customer.h"
#include <QDialog>
#include "tableinfo.h"

namespace Ui {
    class customerView;
}

class customerView : public QDialog
{
    Q_OBJECT

public:
    explicit customerView(QWidget *parent = 0);
    ~customerView();
    void setController(TableController *a, Customer b);
    void refreash();

private slots:

    void on_Small_clicked();

    void on_smallIn_clicked();

    void on_mediumIn_clicked();

    void on_largeIn_clicked();

    void on_Medium_clicked();

    void on_Large_clicked();

private:
    Ui::customerView *ui;
    TableController *tb;
    Customer c;

};

#endif // CUSTOMERVIEW_H

