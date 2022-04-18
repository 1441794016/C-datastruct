#include <iostream>
#define OK 1
#define ERROR 0
typedef double ElemType;
typedef int Status;
typedef struct QNode{
    ElemType  data;
    QNode * next;
} QNode;
typedef struct LinkQueue{
    //保存队列的头指针和尾指针
    QNode * front;
    QNode * rear;
}LinkQueue;

Status InitQueue(LinkQueue & L){
    //创建一个空链队列
    L.front = new QNode;
    L.rear = L.front;
    L.front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue & L){
    while(L.front){
        L.rear = L.front->next;
        delete(L.front);
        L.front = L.rear;
    }
    return OK;
}

Status QueueIncert(LinkQueue & L, ElemType e){
    // 将e插入链队列L
    QNode * q = new QNode ;
    q->data = e;
    q->next = NULL;
    L.rear->next = q;
    L.rear = q;
    return OK;
}

Status QueueDelete(LinkQueue & L, ElemType & e){
    if(L.front == L.rear)
        return ERROR;
    e = L.front->next->data;
    QNode * p = L.front->next;
    if( L.front->next == L.rear){
        L.rear = L.front;
    }
    L.front->next = L.front->next->next;
    delete(p);
    return OK;
}

Status QueueTravel(LinkQueue L, Status(* travel)(ElemType e)){
    QNode * q = L.front->next;
    while(q){
        travel(q->data);
        q = q->next;
    }
    return OK;
}

Status print(ElemType e){
    std::cout<<e<<std::endl;
    return OK;
}

int main() {
    LinkQueue L;
    InitQueue(L);
    QueueIncert(L, 1);
    QueueIncert(L, 2);
    QueueIncert(L, 3);
    QueueIncert(L, 4);
    QueueTravel(L,print);
    ElemType  e;
    QueueDelete(L, e);
    std::cout<<e<<std::endl;
    QueueTravel(L,print);
}
