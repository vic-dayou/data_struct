#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FLASE 0
/*
        队列
和栈相反，队列是一种先进先出的结构（first in first out， FIFO）的线性表。
只允许在表的一段进行插入，而在另一端进行删除。
允许插入的一端叫做队尾（rear）
允许删除的一端叫做队头（front）
*/

typedef int Status;
typedef int QElemType;
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
    QueuePtr front;  //队头指针
    QueuePtr rear;   //队尾指针
}LinkQueue;
//构造一个空的队列Q
Status InitQueue(LinkQueue *q);
//销毁队列Q
Status DestroyQueue(LinkQueue *q);
//清空队列
Status ClearQueue(LinkQueue *q);
//判断队列是否为空，若为空则返回TRUE，否则返回FALSE
Status QueueEmpty(LinkQueue q);
//返回队列的元素个数
int QueueLength(LinkQueue q);
//若队列不为空，则用e返回队头元素，并返回OK，否则返回ERROR
Status GetHead(LinkQueue q, QElemType *e);
//若队列不为空，则用e返回队尾元素，并返回OK，否则返回ERROR
Status GetRear(LinkQueue q, QElemType *e);
//出队列操作，既是删除队头元素，用e返回其值，并返回OK，否则返回ERROR
Status DeQueue(LinkQueue *q, QElemType *e);
//插入新的元素e为队尾元素
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
    {//把头结点计算在内
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
