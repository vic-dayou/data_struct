#include <stdio.h>
#include <stdlib.h>
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
    int i = 5;
    if(InitList(&L) == NULL){
        printf("线性表初始化失败\n");
    }else{
        printf("线性表初始化成功");
    }
    printf("\t insert into SqList \t");
   for(i=0;i<8;i++){
      ListInsert(&L,i+1,i+1);
   }
    TraverseList(&L);
    if(LocalList(&L,4)){
        printf("exist");
    }
    ListDelete(&L,4,&e);
    printf("\tdelete data is: %d\t",e);
    TraverseList(&L);
    SetListValue(&L,3,9);
    TraverseList(&L);
    clearList(&L);
    if(ListEmpty(&L)){
        printf("\nempty");
    }
    DestroyList(&L);
    if(L.elem == NULL){
        printf("\ndestroy");
    }
    return 0;
}
