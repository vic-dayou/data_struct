#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 //链表的最大长度
typedef struct{
    int data;
    int cur;
}component,SLinkList[MAXSIZE];

int main()
{
    SLinkList sl;
    int e = 5;
    InitSpace_SL(sl);
    Create_SL(sl,10);
    Traverse_SL(sl);
    printf("\n-----------------------------------------------\n");
    Insert_SL(sl,4,1);
    Traverse_SL(sl);
    printf("\n-----------------------------------------------\n");
    Delete_SL(sl,5, &e);
  //  printf("e ======= %d",e);
    Traverse_SL(sl);
    printf("\n-----------------------------------------------\n");
    printf("static linked length = %d",Length_SL(sl));
    return 0;
}
