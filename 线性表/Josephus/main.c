#include <stdio.h>
#include <stdlib.h>
/*
    Josephus����
ʹ�õ�ѭ������������ȥ��
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
            p = p->next;   //p�����ƶ�һ���ڵ㣬ʹ��ָ���ɾ���ڵ��ǰһ���ڵ�
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
   for (int i=1; i<index-1; i++){ //�ƶ�����ɾ���ڵ��ǰһ���ڵ�
    if(p->next == linked) break;
        p = p->next;
   }
   CirLinked s = p->next;  // ��ɾ���ڵ�
   CirLinked last = s->next; //��ɾ���ڵ��һ���ڵ�
   p->next = last; //�ѵ�ǰ�ڵ��nextָ���ɾ���ڵ�ĺ�һ���ڵ�
   free(s); //�ͷŽڵ�s

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
