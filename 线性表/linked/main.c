#include <stdio.h>
#include <stdlib.h>
#define ERROR 0;
#define OK 1;
typedef int Status;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
int main()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    ElemType e;
    int i=0;
    for (i=0; i<8; i++){
        InitLinked(L,i+1);
    }
  //  GetElem(L,3,&e);
  //  printf("a = %d",e);
  // TraverseLinked(L);
    InsertLinked(L,4,9);
    printf("\n--------------------------------------------\n");
    TraverseLinked(L);
    printf("\n--------------------------------------------\n");
    DeleteElem(L,4,&e);
    TraverseLinked(L);
    printf("\n--------------------------------------------\n");
    UpdateElem(L,4,9);
    TraverseLinked(L);
    return 0;
}
