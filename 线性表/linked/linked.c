#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define ERROR 0;
#define OK 1;
typedef int Status;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
//insert
Status InitLinked(LinkList head,ElemType e){
    LinkList p = (LinkList)malloc(sizeof(LNode));
    p->data = e;
    p->next = head->next;
    head->next = p;
    return OK;
}
//在第i个元素前插入数据元素
Status InsertLinked(LinkList L,int i,ElemType e){
    LinkList p = L->next;
    int j = 1;
    while(p && j<i-1){
       p = p->next;
       ++j;
    }
    if (!p || j>i-1) return ERROR;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
//删除第i个元素，并将删除的元素返回
Status DeleteElem(LinkList L,int i,ElemType *e){
    LinkList p = L;
    int j=0;
    while (p->next && j < i-1){
        p = p->next;
        ++j;
    }
    if (!(p->next)&&j>i-1) return ERROR; //删除的位置没有元素
    //p->next = p->next->next;
    LinkList q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q); //释放节点
    return OK;
}

//更新第i个元素的值,L必须非空
Status UpdateElem(LinkList L,int i,ElemType new_e){
    LinkList p = L->next;
    int j = 1;
    while (p && j<i){
       p = p->next;
        ++j;
    }
    if(!p || j>i ) return ERROR;
    p->data = new_e;
    return OK;
}
//获取第i个元素
Status GetElem(LinkList L, int i, ElemType *e){
    LinkList p = L->next;
    int j = 1;
    while(p&&j<i){
        p = p->next;
        ++j;
    }
    if(!p || j>i ) return ERROR;
    *e = p->data;
    return OK;
}
void TraverseLinked(LinkList L){
    LinkList p = L->next;
    while(p){
        printf("\t-->%d",p->data);
        p = p->next;
    }

}

