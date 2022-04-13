#include <iostream>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef double ElemType;
#define  LIST_INT_SIZE 100
#define  LISTINCREMENT 10
typedef struct {
    ElemType * elem;
    int length;
    int listsize;
}SqList;

Status InitList(SqList * L){
    //创建一个空的顺序表
    (*L).elem = (ElemType *) malloc(LIST_INT_SIZE * sizeof(ElemType));
    (*L).length = 0;
    (*L).listsize = LIST_INT_SIZE; /* 初始存储容量 */
    return OK;
}

Status ListInsert(SqList * L, int i, ElemType e){
    //在顺序表L的第i个位置之前插入一个新元素e
    if(i<1 || i>( L->length + 1)){
        return ERROR;
    }
    if (L->length >= L->listsize){
        //当前存储空间已满时需要增加分配空间
        ElemType * newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof (ElemType));
        if(!newbase) {
            exit(OVERFLOW);
        }
        L->elem = newbase;
        L->listsize = L->listsize + LISTINCREMENT;
    }
    if(L->length == 0){
        L->elem[0] = e;
        L->length = L->length + 1;
    }
    ElemType * q = &(L->elem[i-1]);  //顺序表中第i个元素的地址
    for(ElemType * p = & (L->elem[L->length - 1]); p >= q; p-- ){
        * (p + 1) = * p;
    }
    L->elem[i-1] = e;
    L->length = L->length + 1;
    return OK;
}

Status ListTraverse(SqList L, void(* Visit)(ElemType *)){
    //遍历操作，对L中每个元素调用函数visit()
    ElemType * p = L.elem;
    for(int i = 1; i <= L.length; i++){
        Visit(p);
        p++;
    }
    return OK;
}

Status ListDelete(SqList * L, int i , ElemType & e){
    //删除第i个元素并用e返回其值
    if ((i < 1) || (i > L->length))
        return ERROR;
    ElemType * p = &(L->elem[i-1]);
    ElemType * q = &(L->elem[L->length-1]);
    e = * p;
    for(; p < q; p++){
        * p  = * (p + 1);
    }
    L->length = L->length - 1;
    return OK;
}

Status LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)){
    //在L中查询第一个满足判定条件的数据元素
    //若存在则返回它的位序，否则返回0
    ElemType * p =L.elem;
    int i = 1;
    while(i <= L.length && !(* compare)(e, *p)){
        i++;
        p++;
    }
    if(i <= L.length)
        return i;
    else
        return 0;
}

Status GetElem(SqList L, int i, ElemType & e){
    //取顺序表中第i个数据元素
    if (i < 1 || i > L.length)
        exit(ERROR);
    e = L.elem[i -1 ];
    return OK;
}

Status equal(ElemType c1, ElemType c2){
    if(c1 == c2)
        return TRUE;
    else
        return FALSE;
}

Status UnionList(SqList * La, SqList Lb){
    //顺序表合并,合并成新的La
    int La_len = La->length;
    int Lb_len = Lb.length;
    for(int i = 1; i <= Lb_len; i++){
         if(!LocateElem(* La, Lb.elem[i - 1], equal))
             ListInsert(La, La->length + 1, Lb.elem[i - 1]);
    }
    return OK;
}

Status MergeList(SqList La, SqList Lb, SqList * Lc){
    // 归并La和Lb得到顺序表Lc la lb lc都递增
    InitList(Lc); //Lc先初始化
    int La_len = La.length;
    int Lb_len = Lb.length;
    int i, j;
    for(i = 0, j = 0; i < La_len && j < Lb_len ;){
        if(La.elem[i] <= Lb.elem[j]) {
            ListInsert(Lc, Lc->length + 1, La.elem[i]);
            i++;
        }
        else {
            ListInsert(Lc, Lc->length + 1, Lb.elem[j]);
            j++;
        }
    }
    if(i >= La_len){
        //表示La已全部归并到Lc中
        while(j < Lb_len){
            ListInsert(Lc, Lc->length + 1, Lb.elem[j]);
            j++;
        }
    }
    if(j >= Lb_len){
        //表示Lb已经全部归并到Lc中
        while(i < La_len){
            ListInsert(Lc, Lc->length + 1, La.elem[i]);
            i++;
        }
    }
    return OK;
}

int ListLength(SqList L){
    return L.length;
}

void print(ElemType * p){
    std::cout<<*p<<std::endl;
}

int main() {
    SqList  La;
    Status i = InitList(&La);
    std::cout<<"the length of La:";
    std::cin>>La.length;
    std::cout<<"please input "<<La.length<<" number(s):"<<std::endl;
    for(int i = 1; i<= La.length; i++){
        std::cin>>La.elem[i - 1];
    }

    std::cout<<"incert number:"<<std::endl;
    ElemType e;
    std::cin>>e;
    ListInsert(&La, La.length + 1, e);
    ListTraverse(La, print);
    ListDelete(&La, 1, e);
    std::cout<<"delete the first number:"<<std::endl;
    ListTraverse(La, print);
    std::cout<<"locate"<<std::endl;
    std::cout<<LocateElem(La, 3, equal)<<std::endl;


    SqList  Lb;
    InitList(&Lb);
    std::cout<<"the length of Lb:";
    std::cin>>Lb.length;
    std::cout<<"please input "<<Lb.length<<" number(s):"<<std::endl;
    for(int i = 1; i<= Lb.length; i++){
        std::cin>>Lb.elem[i - 1];
    }

    SqList Lc;
    MergeList(La, Lb, &Lc);
    std::cout<<"after merge:"<<std::endl;
    ListTraverse(Lc, print);

    UnionList(&La, Lb);
    std::cout<<"after union:"<<std::endl;
    ListTraverse(La, print);


}
