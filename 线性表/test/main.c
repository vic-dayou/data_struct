#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
int main()
{
    SqList L;
    ElemType e;
    int i;
    if(InitList(&L) == NULL){
        printf("\n初始化线性表失败");
    }else{
        printf("\n初始化线性表");
    }
    if(ListEmpty(&L) == TRUE){
        printf("\n线性表为空");
    }else{
        printf("\线性表不为空");
    }
    printf("\t insert into SqList");
    for(i=1;i<=5;i++){
        ListInsert(&L,i,i+1);
    }
    TraverseList(&L);
    return 0;
}
