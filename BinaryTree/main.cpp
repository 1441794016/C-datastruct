//顺序链表并不实用,一般实用链表实现二叉树
//二叉链表
#include <iostream>
#define OK 1
#define ERROR 0
typedef int Status;
typedef char ElemType;
typedef struct BinaryTreeNode{
    ElemType data;
    BinaryTreeNode * lchild, * rchild;
}BinaryTreeNode;

Status BinaryTreeCreate(BinaryTreeNode * & T){
    //按扩展的先序遍历输入
    ElemType data;
    std::cin>>data;
    if(data == '&')
        //输入为& 表示空子树
        T = NULL;
    else{
        //否则就加入新的结点
        T = new BinaryTreeNode;
        T->data = data;
        BinaryTreeCreate(T->lchild);
        BinaryTreeCreate(T->rchild);
    }
    return OK;
}

Status PreOrderTraverse(BinaryTreeNode * T, Status(*traverse)(ElemType e)){
    //先序遍历
    if(T){
        traverse(T->data);
        PreOrderTraverse(T->lchild, traverse);
        PreOrderTraverse(T->rchild, traverse);
    }
    else{
        return OK;
    }
    return OK;
}

Status print(ElemType e){
    std::cout<<e;
}

int main() {
    BinaryTreeNode * T;
    BinaryTreeCreate(T);
    PreOrderTraverse(T,print);
}
