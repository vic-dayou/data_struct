#include <stdio.h>
#include <stdlib.h>
/*
            ����������Լɪ�������ǿ�棩
���Ϊ1~N��N���˰�˳ָ�뷽��Χ��һȦ��ÿ���˳���һ������
�ӵ�һ���˰��������루������M����ʼ����,����M���˱���Mʱ
���˳��У���������K��Ϊ�´α���������ֵ��������ȥ��ֱ�������˳���
*/
typedef struct Josephus2{
    int data;
    struct Josephus2 *next;
}Josephus2,*JLinked;
//�����յĵ�ѭ������
JLinked Init_Linked(int n){
    JLinked head = (JLinked)malloc(sizeof(JLinked));
    head->next = NULL;
    JLinked p = head;
    int i = 1;
    //����ѭ��������������
    srand(time(0));
    while(i<=n){
        JLinked temp = (JLinked)malloc(sizeof(JLinked));
        temp->next = p->next;
        temp->data = rand()%10+1;
        p->next = temp;
        p = temp;
        i++;
    }
    //ʹβ�ڵ��nextָ��head->next,����ͷ�headʹ���ѭ������
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
