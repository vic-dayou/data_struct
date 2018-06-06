#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct CirLNode{
    int data;
    int length;
    struct CirLNode *prior;
    struct CirLNode *next;
}CirLNode, *CirLinked;
int main()
{
    /*
    CirLinked cl = Init_CL();
    for(int i=0;i<=5;i++){
        Insert_CL(cl,2,i++);
    }
    Traversal(cl);
    */
    CirLinked c = Create_CL(8);
    Traversal(c);
    Insert_CL(c,3,9);
    printf("\n-----------------------------------------------\n");
    Traversal(c);
     printf("\n-----------------------------------------------\n");
    int e;
    printf("É¾³ýµÄÔªËØÎª£º%d",Delete_CL(c,6,&e));
    Traversal(c);
    printf("\n-----------------------------------------------\n");
    return 0;
}

