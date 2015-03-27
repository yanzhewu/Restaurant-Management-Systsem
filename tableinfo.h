#ifndef TABLEINFO_H
#define TABLEINFO_H
#include "tablecontroller.h"
#include <QDialog>

namespace Ui {
    class TableInfo;
}

class TableInfo : public QDialog
{
    Q_OBJECT

public:
    explicit TableInfo(QWidget *parent = 0);
    ~TableInfo();
    void setcontroller(TableController *a);

private:
    Ui::TableInfo *ui;
    TableController *tc;
};

#endif // TABLEINFO_H
