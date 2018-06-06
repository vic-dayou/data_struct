#include <stdio.h>
#include <stdlib.h>
typedef struct DuLNode{
    unsigned int data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

int main(void)
{
    DuLinkList du = (DuLinkList)malloc(sizeof(DuLNode));
    Init_DL(du);
  //  Insert_DL(du,1,5);
    for (int i=0; i<8; i++){
        Insert_DL(du,1,i+1);
    }
    TraverseLinked(du);
    printf("\n---------------------------\n");
    Delete_DL(du,2);
    TraverseLinked(du);
    return 0;
}

