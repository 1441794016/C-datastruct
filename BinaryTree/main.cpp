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
    if(data == '.')
        //输入为. 表示空子树
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

Status InOrderTraverse(BinaryTreeNode * T, Status(*traverse)(ElemType e)){
    //中序遍历
    if(T){
        InOrderTraverse(T->lchild, traverse);
        traverse(T->data);
        InOrderTraverse(T->rchild,traverse);
    }
    return OK;
}

Status PostOrderTraverse(BinaryTreeNode * T, Status(* traverse)(ElemType e)){
    //后序遍历 LRD
    if(T){
        PostOrderTraverse(T->lchild, traverse);
        PostOrderTraverse(T->rchild,traverse);
        traverse(T->data);
    }
    return OK;
}

Status CountLeaf(BinaryTreeNode * T, int & count){
    //统计链表二叉树T的叶子结点的个数
    if(T) {
        if ((T->lchild == NULL) && (T->rchild == NULL))
            count++;
        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
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
    std::cout<<std::endl;
    InOrderTraverse(T,print);
    std::cout<<std::endl;
    int count = 0;
    CountLeaf(T, count);
    std::cout<<count;
}
