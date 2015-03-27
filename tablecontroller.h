#ifndef TABLECONTROLLER_H
#define TABLECONTROLLER_H
#include<vector>
#include<QQueue>
#include"table.h"
#include<customer.h>

using namespace::std;

class TableController
{
    int largeSize ;
    int mediumSize ;
    int smallSize;

    QQueue<Customer> largeQueue;
    QQueue<Customer> mediumQueue;
    QQueue<Customer> smallQueue;
    int getAvaTable(int size);

public:
    TableController();
    Table large[5];
    Table medium[10];
    Table small[15];
    void allocateTable(int size, Customer &tc);//分配桌子
    int waitForTable(int size, Customer tc);//把顾客加入等待队列
    int releaseTable(int size, int id);//释放桌子
    bool checkTableByID(int id);//暂且没有实现
    int checkQueueBySize(int size);//根据桌子大小检测等待队列长度
    int outOfQueue(int size);//顾客出队
    int avaTableNum(int size);//可用桌数
    int getAvaTableID(int size);//可用桌号
    int getQueueNum(int size);//排队人数
    int getCurrentCustomerID(int size);//获得当前排号
    void initial();
};

#endif // TABLECONTROLLER_H
