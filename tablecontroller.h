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
    void allocateTable(int size, Customer &tc);//��������
    int waitForTable(int size, Customer tc);//�ѹ˿ͼ���ȴ�����
    int releaseTable(int size, int id);//�ͷ�����
    bool checkTableByID(int id);//����û��ʵ��
    int checkQueueBySize(int size);//�������Ӵ�С���ȴ����г���
    int outOfQueue(int size);//�˿ͳ���
    int avaTableNum(int size);//��������
    int getAvaTableID(int size);//��������
    int getQueueNum(int size);//�Ŷ�����
    int getCurrentCustomerID(int size);//��õ�ǰ�ź�
    void initial();
};

#endif // TABLECONTROLLER_H
