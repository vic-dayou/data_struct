#include <stdio.h>
#include <stdlib.h>
/*
    Josephus问题
使用单循环链表，逢三除去。
*/
typedef struct Josephus{
    int data;
    struct Josephus *next;
}Josephus,*CirLinked;

CirLinked Init_Linked(int n){
    CirLinked head = (CirLinked)malloc(sizeof(CirLinked));
    head->next = NULL;
    CirLinked p = head;
    int i = 1;
    while(i<=n){
        CirLinked temp = (CirLinked)malloc(sizeof(CirLinked));
        temp->next = p->next;
        temp->data = i;
        p->next = temp;
        p = temp;
        i++;
    }
    p->next = head->next;
    free(head);
    return p->next;
}
void Traversal_Linked(CirLinked linked){
    int i=1;
    CirLinked p = linked;
    while(1){
        printf("data[%d]=%d\t",i,p->data);
        p = p->next;
        if(p == linked) break;
        i++;
    }
}

void Play(CirLinked linked){
    int n = 41;
    int m = 3;
    CirLinked p = linked;
    CirLinked temp;
    m %= n;
    while(p != p->next){
        for (int i=1; i<m-1; i++)
        {
            p = p->next;   //p往后移动一个节点，使其指向待删除节点的前一个节点
        }
        printf("%d->\t",p->next->data);
        temp = p->next;
        p->next = temp->next;
        free(temp);
        p=p->next;
    }
    printf("%d\n",p->data);

}

int Delete_Linked(CirLinked linked,int index){
   CirLinked p = linked;
   for (int i=1; i<index-1; i++){ //移动到待删除节点的前一个节点
    if(p->next == linked) break;
        p = p->next;
   }
   CirLinked s = p->next;  // 待删除节点
   CirLinked last = s->next; //待删除节点后一个节点
   p->next = last; //把当前节点的next指向待删除节点的后一个节点
   free(s); //释放节点s

   return 1;
}

int main()
{
    CirLinked c = Init_Linked(41);
  //  Traversal_Linked(c);
    printf("\n-----------------------------------------------------\n");
  //  Delete_Linked(c,8);
  // Traversal_Linked(c);
    Play(c);
    return 0;
}
