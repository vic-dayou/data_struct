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
        printf("\n��ʼ�����Ա�ʧ��");
    }else{
        printf("\n��ʼ�����Ա�");
    }
    if(ListEmpty(&L) == TRUE){
        printf("\n���Ա�Ϊ��");
    }else{
        printf("\���Ա�Ϊ��");
    }
    printf("\t insert into SqList");
    for(i=1;i<=5;i++){
        ListInsert(&L,i,i+1);
    }
    TraverseList(&L);
    return 0;
}
