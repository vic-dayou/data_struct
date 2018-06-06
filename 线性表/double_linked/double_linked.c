#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define ERROR 0
#define OK 1
/*
    双向链表
双向链表有两个指针*prior和*next，它们分别指向自身的直接前驱和直接后继
头结点的直接前驱为NULL
尾节点的直接后继为NULL
它们可以从一个节点双向的访问链表

*/
typedef struct DuLNode{
    unsigned int data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;
//初始化双向链表
int Init_DL(DuLinkList linked);
//遍历链表
void TraverseLinked(DuLinkList linked);
//插入元素
int Insert_DL(DuLinkList linked,int index,int e);
//刪除元素并將刪除元素返回給e
int Delete_DL(DuLinkList linked,int index);

int Init_DL(DuLinkList linked){
 //   linked = (DuLinkList)malloc(sizeof(DuLinkList));
    if(linked){
        linked->next = NULL;
        linked->prior = NULL;
        linked->data = 0;
    }else{
        return ERROR;
    }
    return OK;
}
DuLinkList Create_DL(){
    DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));
    if(!s){
        printf("malloc has failed");
        exit(0);
    }else{
        return s;
    }
}
int Insert_DL(DuLinkList linked,int index,int e){
//判断当前链表是否只有一个头结点，若是只有一个头结点，则不论index为和值，都在头结点后面插入一个元素
    DuLinkList s;
    if(!linked){
        return ERROR;
    }else{
        s = Create_DL();
    }
    if(!linked->next){
//        DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));
       // DuLinkList s = Create_DL();
        s->data = e;
        s->prior = linked;
        s->next = linked->next;
        linked->next = s;
        return OK;
    }
    DuLinkList p = linked->next;
    for (int i=1;i<index; i++){
        p = p->next;
    }
  //  DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));

    if(!s) return ERROR;
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}
int Local_DL(DuLinkList linked, int index){
    DuLinkList p = linked->next;
    int flag = 0;
    for (int i=1;i<index ;i++ ){
        p = p->next;
        if(!p) break;
    }
    if(!p){
        return ERROR;
    }else{
        return OK;
    }

}
int Delete_DL(DuLinkList linked,int index){
   //如果删除的是链表中的最后一个
    if(!Local_DL(linked,index))
    {   printf("index 非法");
        return ERROR; //index非法
    }
    DuLinkList p = linked->next;
    if (!(p->next)){
        p->prior->next = p->next;
        free(p);
        return OK;
    }
    //如果不是最后一个，则找到待删除位置
    for (int i=1; i<index; i++){
        p = p->next;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

void TraverseLinked(DuLinkList linked){
    //linked作为头结点不存放数据
    DuLinkList p = linked->next;
    while(p){
        printf("-->%d\t",p->data);
        p = p->next;
    }

}
