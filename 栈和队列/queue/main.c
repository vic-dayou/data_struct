#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FLASE 0
/*
        ����
��ջ�෴��������һ���Ƚ��ȳ��Ľṹ��first in first out�� FIFO�������Ա�
ֻ�����ڱ��һ�ν��в��룬������һ�˽���ɾ����
��������һ�˽�����β��rear��
����ɾ����һ�˽�����ͷ��front��
*/

typedef int Status;
typedef int QElemType;
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
    QueuePtr front;  //��ͷָ��
    QueuePtr rear;   //��βָ��
}LinkQueue;
//����һ���յĶ���Q
Status InitQueue(LinkQueue *q);
//���ٶ���Q
Status DestroyQueue(LinkQueue *q);
//��ն���
Status ClearQueue(LinkQueue *q);
//�ж϶����Ƿ�Ϊ�գ���Ϊ���򷵻�TRUE�����򷵻�FALSE
Status QueueEmpty(LinkQueue q);
//���ض��е�Ԫ�ظ���
int QueueLength(LinkQueue q);
//�����в�Ϊ�գ�����e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
Status GetHead(LinkQueue q, QElemType *e);
//�����в�Ϊ�գ�����e���ض�βԪ�أ�������OK�����򷵻�ERROR
Status GetRear(LinkQueue q, QElemType *e);
//�����в���������ɾ����ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
Status DeQueue(LinkQueue *q, QElemType *e);
//�����µ�Ԫ��eΪ��βԪ��
Status EnQueue(LinkQueue *q, QElemType e);


Status InitQueue(LinkQueue *q)
{
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(! q->front) exit(-1);
    q->front->next=NULL;
    return OK;
}
Status DestroyQueue(LinkQueue *q)
{
    while (q->front)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    return OK;
}
Status EnQueue(LinkQueue *q, QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(-1);
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return OK;
}

Status DeQueue(LinkQueue *q, QElemType *e)
{
    if(q->front == q->rear) return ERROR;
    QueuePtr p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p) q->rear = q->front;
    free(p);
    return OK;
}

Status GetHead(LinkQueue q, QElemType *e)
{
    if(q.front == q.rear) exit(-1);
    QueuePtr p = q.front->next;
    *e = p->data;
    return OK;
}
Status GetRear(LinkQueue q, QElemType *e)
{
    if(q.front == q.rear) exit(-1);
    QueuePtr p = q.rear;
    *e = p->data;
    return OK;
}
int QueueLength(LinkQueue q)
{
    /*
    QueuePtr p = q.front->next;
    int len = 1;
    while(p->next)
    {
        p = p->next;
        len++;
    }
    */


    int len=0;
    while (q.front)
    {//��ͷ����������
        q.rear = q.front->next;
        q.front = q.rear;
        len++;
    }

    return len;
}
Status QueueEmpty(LinkQueue q)
{
    if(q.front != q.rear) return TRUE;
    return FLASE;
}
Status ClearQueue(LinkQueue *q)
{
    while(1)
    {
        QueuePtr p = q->front->next;
        q->front->next = p->next;
        if(q->rear == p) q->rear = q->front;
        free(p);
        if(q->front == q->rear) break;
    }

}
int main()
{
    LinkQueue q;
    InitQueue(&q);
    int e;
    int len;
    printf("%d",QueueEmpty(q));
    for (int i=0; i<5;i++ )
    {
        EnQueue(&q,i);
    }
    printf("%d",QueueEmpty(q));
    //ClearQueue(&q);
    //printf("%d",QueueEmpty(q));
    //GetHead(q, &e);
    //GetRear(q,&e);
  //  DeQueue(&q,&e);
   // printf("%d",e);
    //len = QueueLength(q);
    //printf("%d",len);
    return 0;
}
