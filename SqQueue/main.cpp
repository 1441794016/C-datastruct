//顺序队列一般使用循环队列
#include <iostream>
#include <vector>
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
typedef double ElemType;
typedef int Status;
typedef struct SqQueue{
    ElemType * base;
    int front;
    int rear;
}SqQueue;

Status InitSqQueue(SqQueue & Q){
    //创建一个空队列Q
    Q.base = new ElemType [MAXQSIZE];
    Q.front = Q.rear = 0;
    return OK;
}

Status SqQueueIncert(SqQueue & Q, ElemType e){
    if(Q.front == (Q.rear + 1) % MAXQSIZE)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE ;
    return OK;
}

Status SqQueueDelete(SqQueue & Q, ElemType & e){
    //队列头删除
    if(Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

Status SqQueueTravel(SqQueue Q, Status(* travel)(ElemType e)){
    int ind = Q.front;
    while(ind < Q.rear){
        travel(Q.base[ind]);
        ind++;
    }
}

Status print(ElemType e){
    std::cout<<e<<std::endl;
}

int main() {
    SqQueue q;
    InitSqQueue(q);
    SqQueueIncert(q, 3);
    SqQueueIncert(q, 4);
    SqQueueTravel(q,print);
    ElemType  e;
    SqQueueDelete(q, e);
    SqQueueTravel(q,print);

}
