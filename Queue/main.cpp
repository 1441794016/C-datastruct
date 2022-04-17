#include <iostream>
#define OK 1
#define ERROR 0
typedef double ElemType;
typedef struct QNode{
    ElemType  data;
    QNode * next;
} QNode;
typedef struct LinkQueue{
    //保存队列的头指针和尾指针
    QNode * front;
    QNode * rear;
}LinkQueue;
int main() {
   
}
