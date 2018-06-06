#include <stdio.h>
#include <stdlib.h>
/*
            问题描述（约瑟夫问题加强版）
编号为1~N的N个人按顺指针方向围坐一圈，每个人持有一个密码
从第一个人按照其密码（正整数M）开始报数,当第M个人报道M时
此人出列，将其密码K作为下次报数的上限值。依次下去，直到所有人出列
*/
typedef struct Josephus2{
    int data;
    struct Josephus2 *next;
}Josephus2,*JLinked;
//创建空的单循环链表
JLinked Init_Linked(int n){
    JLinked head = (JLinked)malloc(sizeof(JLinked));
    head->next = NULL;
    JLinked p = head;
    int i = 1;
    //整个循环创建单向链表
    srand(time(0));
    while(i<=n){
        JLinked temp = (JLinked)malloc(sizeof(JLinked));
        temp->next = p->next;
        temp->data = rand()%10+1;
        p->next = temp;
        p = temp;
        i++;
    }
    //使尾节点的next指向head->next,最后释放head使其成循环链表
    p->next = head->next;
    free(head);
    return p->next;
}
void Traversal_Linked(JLinked linked){
    int i=1;
    JLinked p = linked;
    while(1){
        printf("data[%d]=%d\t",i,p->data);
        p = p->next;
        if(p == linked) break;
        i++;
    }
}
void Play(JLinked linked){
    JLinked p = linked;
    int key = p->data;
    JLinked temp;
    while (p != p->next)
    {
        for (int i=1;i<key-1;i++)
        {
          p = p->next;
        }
        temp = p->next;
        printf("--->%d\t",temp->data);
        p->next = temp->next;
        key = temp->data;
        p = p->next;
    }
    printf("%d ",p->data);
}
int main()
{
    JLinked js= Init_Linked(41);
    Traversal_Linked(js);
    printf("\n------------------------------------\n");
    Play(js);
    return 0;
}
