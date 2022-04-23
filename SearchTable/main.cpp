#include <iostream>
#define OK 1
#define ERROR 0
typedef double ElemType;
typedef int Status;
ElemType r[5] = {1, 2, 3, 4, 5};
typedef struct SSTable{
    ElemType * data;
    int length; //表的长度
}SSTable;

Status CreateSTable(SSTable & T, int n){
    T.data = new ElemType [n + 1]; //下标为0的单元作为哨兵
    if(!T.data)
        return ERROR;
    for(int i = 1; i <= n; i++){
        T.data[i] = r[i - 1];
    }
    T.length = n;
    return OK;
}

int SeqSearch(SSTable T, ElemType key){
    //在顺序表中顺序查找等于key的关键元素
    int i;
    T.data[0] = key;
    for(i = T.length + 1; T.data[i] != key; i--){
        //找不到i为0
    };
    return i;
}

int BinSearch(SSTable T, ElemType key){
    //折半查找，要求T是有序表
    int low = 1;
    int high = T.length;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(T.data[mid] == key)
            return mid;
        else if(T.data[mid] < key){
            low = mid + 1;
            }
            else{
            high = mid - 1;
            }
    }
    return 0;
}

int main() {
    SSTable  T;
    CreateSTable(T, 5);
    std::cout<<SeqSearch(T, 6)<<std::endl;
    std::cout<<BinSearch(T, 1)<<std::endl;
}
