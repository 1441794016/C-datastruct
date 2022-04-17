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

Status ListIncert(LNode * L, int i, ElemType e){
    //带头结点的单链表中在第i个元素前插入e
    LNode * s = new LNode;
    s->data = e;
    int j = 0;
    LNode * p = L;
    while(j < i - 1){
        p = p->next;
        j++;
        if(p == NULL || i < 1)
            return ERROR;
    }
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LNode * L, int i, ElemType & e){
    //删除链表中第i个结点
    if (i < 1)
        return ERROR;
    LNode * p = L;
    int j = 0;
    while(j < i - 1){
        p = p->next;
        j++;
        if(p == NULL)
            return ERROR;
    }
    LNode * q = p->next;
    e = q->data;
    p->next = p->next->next;
    delete(q);
    return OK;
}

Status ListTravel(LNode * L, Status(* travel)(ElemType e)){
    LNode * p = L;
    while(p->next != NULL){
        p = p->next;
        travel(p->data);
    }
    return OK;
}

Status MergeList(LNode * La, LNode * Lb, LNode * & Lc){
    //两个链表的归并
    //La Lb都是递增,归并成新的Lc
    LNode * p = La;
    LNode * q = Lb;
    Lc = new LNode;
    Lc->next = NULL;
    LNode * b = Lc;
    p = p->next;
    q = q->next;
    LNode * s;
    while(p && q){
        if(p->data <= q->data){
            s = new LNode;
            s->data = p->data;
            b->next = s;
            b = s;
            p = p->next;
        }
        else{
            s = new LNode;
            s->data = q->data;
            b->next = s;
            b = s;
            q = q->next;
        }
    }
    if(p == NULL){
        // 表示La已全部归并完
        while(q){
            s = new LNode;
            s->data = q->data;
            b->next = s;
            b = s;
            q = q->next;
        }
    }
    else{
        while(p){
            s = new LNode;
            s->data = p->data;
            b->next = s;
            b = s;
            p = p->next;
        }
    }
    return OK;

}

Status print(ElemType e){
    std::cout<<e<<std::endl;
}

int main() {
    LNode * List;
    int n ;
    std::cin>>n;
    CreateList(List, n);
    ElemType e;
//    GetElem(List, 5, e);
//    std::cout<<e<<std::endl;
    ListIncert(List, 1, 0);
    ListTravel(List, print);
    ListDelete(List, 5, e);
    std::cout<<"e: "<<e<<std::endl;
    ListTravel(List, print);

    LNode * List2;
    std::cin>>n;
    CreateList(List2, n);
    LNode * List3;
    MergeList(List, List2, List3);
    ListTravel(List3, print);
}
