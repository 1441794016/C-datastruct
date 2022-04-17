//顺序栈的实现
#include <iostream>
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define OK 1
#define ERROR 0
typedef double ElemType;
typedef int Status;
typedef struct SqStack{
    ElemType * base;
    ElemType * top; //栈顶,初值指向栈底,永远指向下一次要插入的位置
    int stacksize; //当前分配的存储空间
}SqStack;

Status InitStack(SqStack & s){
    s.base = (ElemType *) malloc(STACK_INIT_SIZE * sizeof(ElemType));
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack s, ElemType e){
    //在栈顶插入新的元素e
    if( (s.top - s.base) >= s.stacksize){
        //存储空间已满需增加分配
        s.base = (ElemType *) realloc(s.base, (s.stacksize + STACK_INCREMENT) * sizeof(ElemType));
        s.top = s.base + s.stacksize;
        s.stacksize = s.stacksize + STACK_INCREMENT;
    }
    * s.top = e;
    s.top++;
    return OK;
}

Status Pop(SqStack s, ElemType & e){
    if(s.top = s.base){
        return ERROR;
    }
    s.top--;
    e = * s.top;
    return OK;
}

int main() {

}
