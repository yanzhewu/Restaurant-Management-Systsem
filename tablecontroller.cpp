#include "tablecontroller.h"



using namespace::std;

TableController::TableController()//构造函数
{

}

void TableController::initial(){
    largeSize = 5;
    for(int i=0;i<largeSize;i++){
        large[i]=Table(3,i+300,200,0,true);
    }

    mediumSize = 10;
    for(int i=0;i<mediumSize;i++){
        medium[i]=Table(2,i+200,100,0,true);
    }

    smallSize = 15;
    for(int i=0;i<smallSize;i++){
        small[i]=Table(1,i+100,50,0,true);
    }
}

void TableController::allocateTable(int size, Customer &tc)//分配桌子
{
    int tmp;
    switch(size){
        case 1:
                tmp = getAvaTable(1);
                small[tmp].setCustomer(tc);
                small[tmp].setState(false);
                tc.setTableID(small[tmp].returnTableID());
                break;
        case 2:
                tmp = getAvaTable(2);
                medium[tmp].setCustomer(tc);
                medium[tmp].setState(false);
                tc.setTableID(medium[tmp].returnTableID());
                break;
        default:
                tmp = getAvaTable(3);
                large[tmp].setCustomer(tc);
                large[tmp].setState(false);
                tc.setTableID(large[tmp].returnTableID());
                break;
    }
}
int TableController::getAvaTableID(int size){//获取有空的桌子

    switch(size){
        case 1:
        for(int i=0;i<smallSize;i++){
            if(small[i].isAva()){
                return small[i].returnTableID();
            }
        }
              return -1;
        case 2:
        for(int i=0;i<mediumSize;i++){
            if(medium[i].isAva()){
                return medium[i].returnTableID();
            }
        }
        return -1;
        default:
        for(int i=0;i<largeSize;i++){
            if(large[i].isAva()){
                return large[i].returnTableID();
            }
        }
        return -1;
    }
    return -1;
}

int TableController::getAvaTable(int size){//获取有空的桌子

    switch(size){
        case 1:
        for(int i=0;i<smallSize;i++){
            if(small[i].isAva()){
                return i;
            }
        }
              return -1;
        case 2:
        for(int i=0;i<mediumSize;i++){
            if(medium[i].isAva()){
                return i;
            }
        }
        return -1;
        default:
        for(int i=0;i<largeSize;i++){
            if(large[i].isAva()){
                return i;
            }
        }
        return -1;
    }
    return -1;
}

int TableController::waitForTable(int size, Customer tc){
    switch(size){
    case 1:
        smallQueue.push_back(tc);
        return smallQueue.size();
    case 2:
        mediumQueue.push_back(tc);
        return mediumQueue.size();
    case 3:
        largeQueue.push_back(tc);
        return largeQueue.size();
    default:
        return 0;
    }
}

bool TableController::checkTableByID(int id){
    if(id>=300){
        for(int i=0;i<smallSize;i++){
            if(small[i].returnTableID()==id);
        }
    }
}

int TableController::releaseTable(int size, int id){
    switch(size){
    case 1:
    for(int i=0;i<smallSize;i++){
        if(small[i].returnTableID()==id)
            small[i].setState(true);
        small[i].customerID = 0;
    }
        return 1;
    case 2:
        for(int i=0;i<mediumSize;i++){
            if(medium[i].returnTableID()==id)
                medium[i].setState(true);
                medium[i].customerID = 0;
        }
       return 1;
    case 3:
        for(int i=0;i<largeSize;i++){
            if(large[i].returnTableID()==id)
                large[i].setState(true);
            large[i].customerID = 0;
        }
        return 1;
    }
    return -1;
}

int TableController::checkQueueBySize(int size){
    switch(size){
    case 1:
       return smallQueue.size();
    case 2:
       return mediumQueue.size();
    case 3:
       return largeQueue.size();
    }
    return -1;
}

int TableController::outOfQueue(int size){
    Customer tmp;
    switch(size){
    case 1:
       tmp=smallQueue.first();
       smallQueue.pop_front();      
       return tmp.getID();
    case 2:
        tmp=mediumQueue.first();
        mediumQueue.pop_front();
        return tmp.getID();
    case 3:
        tmp=largeQueue.first();
        largeQueue.pop_front();
        return tmp.getID();
    }
    return -1;
}

int TableController::avaTableNum(int size){
    int num = 0;
    switch(size){
    case 1:
        for(int i=0;i<smallSize;i++){
            if(small[i].isAva()){
               num++;
            }
        }
        return num;
    case 2:
    for(int i=0;i<mediumSize;i++){
        if(medium[i].isAva()){
            num++;
        }
    }
    return num;
    default:
    for(int i=0;i<largeSize;i++){
        if(large[i].isAva()){
            num++;
        }
    }
    return num;
    }
    return num;
}

int TableController::getQueueNum(int size){
    int num = 0;
    switch(size){
    case 1:
        num=smallQueue.size();
        return num;
    case 2:
    num=mediumQueue.size();
    return num;
    default:
    num=largeQueue.size();
    return num;
    }
    return num;
}

int TableController::getCurrentCustomerID(int size){
    Customer tmp;
    int num = 0;
    switch(size){
    case 1:
        if(smallQueue.size()==0){
            return num = 0;
        }
        else{
            tmp = smallQueue.first();
            return tmp.getID();
        }

    case 2:
        if(mediumQueue.size()==0){
            return num = 0;
        }
        else{
            tmp = mediumQueue.first();
            return tmp.getID();
        }

    return num;
    default:
        if(largeQueue.size()==0){
            return num = 0;
        }
        else{
            tmp = largeQueue.first();
            return tmp.getID();
        }

    return num;
    }
    return num;
}
