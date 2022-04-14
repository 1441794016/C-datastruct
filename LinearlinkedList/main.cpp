#include <iostream>
#define OK 1
#define ERROR 0
typedef int Status;
typedef double ElemType;
//结点类型
struct LNode{
    ElemType data;
    LNode * next;
};
//指向结点的指针类型
typedef LNode * LinkList;

Status CreateList(LNode * &L, int n){
    //头结点的指针L，输入的元素个数n
    //逆序输入
    L = new LNode;
    L->next = NULL; //先建立只带头结点的单链表
    for(int i = 0; i < n; i++){
        LNode * p = new LNode;
        std::cin>>p->data;
        p->next = L->next;
        L->next = p;
    }
    return OK;
}

Status GetElem(LNode * L, int i, ElemType & e){
    //取单链表中第i个元素，并用e返回
    if(i<1)
        return ERROR;
    LNode * p = L;
    int j = 0;
    while( p && j < i){
        p = p->next;
        j++;
    }
    if(p == NULL)
        return ERROR;
    else
        e = p->data;
    return  OK;
}

int main() {
    LNode * List;
    int n ;
    std::cin>>n;
    CreateList(List, n);
    ElemType e;
    GetElem(List, 5, e);
    std::cout<<e;
}
