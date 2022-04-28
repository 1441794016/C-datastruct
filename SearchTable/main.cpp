#include <iostream>
#include<cmath>
#define OK 1
#define ERROR 0
typedef double ElemType;
typedef int Status;
ElemType r[5] = {1, 0, 1, 4, 3};
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

void InsertSort(SSTable & T){
    //直接插入排序
    int i = 2;
    int j;
    for(; i <= T.length; i++){
        if(T.data[i] < T.data[i - 1]){
            T.data[0] = T.data[i];
            for(j=i-1; j>=0; j--){
                if(T.data[j] > T.data[0]){
                    T.data[j + 1] = T.data[j];
                }else{
                    T.data[j + 1] = T.data[0];
                    break;
                }
            }
        }
    }
}

void BinInsertSort(SSTable & T){
    //折半排序
    for(int i = 1; i < T.length; i++){
        int low = 1;
        int high = i;
        T.data[0] = T.data[i + 1];
        int mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(T.data[mid] < T.data[i + 1]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        for(int j = i + 1; j > low; j--){
            T.data[j] = T.data[j - 1];
        }
        T.data[low] = T.data[0];
    }
}

void ShellInsertSort(SSTable & T, int dt){
    //希尔排序中需要用到的直接插入排序
    int j;
    for(int k = 1; k <= dt; k++){
        for(int i = k + dt; i <= T.length; i+=dt){
            if(T.data[i] < T.data[i-dt]){
                T.data[0] = T.data[i];
                for(j=i-dt;j>=k;j-=dt){
                    if(T.data[j] > T.data[0]){
                        T.data[j+dt] = T.data[j];
                    }else{
                        T.data[j+dt] = T.data[0];
                        break;
                    }
                }
                if(j<k){
                    T.data[k] = T.data[0];
                }
            }
        }
    }
}

void ShellSort(SSTable & T){
    //希尔排序
    for(int dt = T.length / 2; dt >= 1; dt = dt / 2){
        ShellInsertSort(T, dt);
    }
}

void QSort(SSTable & T, int low, int high){
    T.data[0] = T.data[low]; //key保存枢轴的值
    ElemType key = T.data[0];
    int i = low;
    int j = high;
    while(i < j){
        while(T.data[j] >= key && i < j)
            j--;
        T.data[i] = T.data[j];
        T.data[j] = key;
        while(T.data[i] <= key && i < j)
            i++;
        T.data[j] = T.data[i];
        T.data[i] = key;
    }
    QSort(T, low, i-1);
    QSort(T, i+1, high);
}

void TableTraverse(SSTable T, void(* traverse)(ElemType e)){
    int n = T.length;
    for(int i = 1;i <= n; i++){
        traverse(T.data[i]);
    }
}

void print(ElemType e){
    std::cout<<e;
}

int main() {
    SSTable T;
    SSTable T1;
    SSTable T2;
    SSTable T3;
    CreateSTable(T, 5);
    CreateSTable(T1, 5);
    CreateSTable(T2, 5);
    CreateSTable(T3, 5);
    std::cout<<SeqSearch(T, 6)<<std::endl;
    std::cout<<BinSearch(T, 1)<<std::endl;
    InsertSort(T);
    TableTraverse(T,print);
    std::cout<<std::endl;
    BinInsertSort(T1);
    TableTraverse(T1,print);

    std::cout<<std::endl;
    ShellSort(T2);
    TableTraverse(T2,print);

    std::cout<<std::endl;
    QSort(T3, 1, T3.length);
    TableTraverse(T3,print);
}
