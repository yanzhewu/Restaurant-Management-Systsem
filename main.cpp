#include <QtGui/QApplication>
#include "tablecontroller.h"
#include "resturant.h"
#include "login.h"
#include "customerview.h"
#include "cashierview.h"





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));


    Login l;
    TableController tc;
    tc.initial();
    l.setController(&tc);

    l.show();

    qApp->setStyle(new QPlastiqueStyle);
    return a.exec();


}
