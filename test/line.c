#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

/*初始化一个空的线性表*/
//Status InitList(SqList *L);
/*销毁线性表*/
//void DestroyList(SqList *L);
/*置空线性表*/
//void clearList(SqList *L);
/*判断线性表是否为空*/
//Status ListEmpty(SqList *L)
/*用e返回L中第i个数据元素的值*/
//Status GetElem(SqList *L,int i,ElemType *e);
/*获取元素cur_e的直接前驱*/
//Status PriorElem(SqList *L,ElemType cur_e,ElemType *prior_e);
/*获取元素cur_e的直接后继*/
//Status NextElem(SqList *L,ElemType cur_e,ElemType *next_e);
/*在位置i的前面插入数据元素*/
//Status ListInsert(SqList *L,int i,ElemType e);
/*删除位置i处的数据元素返回给e*/
//Status ListDelete(SqList *L,int i,ElemType *e);
/*对线性表内数据元素进行排序,从小到大*/
//void ListSort_SqList(SqList *L);
/*倒置线性表中的所有数据元素*/
//void ListInvert_SqList(SqList *L);


Status InitList(SqList *L){
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(! L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

void DestroyList(SqList *L){
    if(L->elem != NULL){
        L->elem=NULL;   //释放线性表内存空间
        L->length=0;
        L->listsize=0;
    }
}

void clearList(SqList *L){
    L->length=0;
}

Status ListEmpty(SqList *L){
    if(L->length == 0) {
        return TRUE;
    }else{
        return FALSE;
    }
}
Status GetElem(SqList *L,int i,ElemType *e){
    if(i < 1 || i > L->length) return ERROR;
    if(L->elem == NULL) return ERROR;
    *e = L->elem[i-1];
    return OK;
}
Status PriorElem(SqList *L,ElemType cur_e,ElemType* prior_e){
    if(cur_e == L->elem[0]) return ERROR;    //第一个元素没有直接前驱
    int i=2;
    while(i < L->length) {
        if(L->elem[i-1] == cur_e){
            *prior_e = L->elem[i-2];
            return OK;
        }
        i++;
    }
    return ERROR;
}
Status NextElem(SqList *L,ElemType cur_e,ElemType* next_e){
    if(cur_e == L->elem[L->length-1]) return ERROR; //最后一个元素没有直接后继
    int i=0;
    while(i < L->length-1){
        if(L->elem[i] == cur_e){
            *next_e = L->elem[i+1];
            return OK;
        }
        i++;
    }
    return ERROR;
}
Status ListInsert(SqList *L,int i,ElemType e){
    if(i<1 || i>L->length) return ERROR; //i值不合法
    if(L->length >= L->listsize) { //当前内存已满，增加分配
        ElemType *newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(! newbase) exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    ElemType *q = &(L->elem[i-1]); //q为插入位置
    ElemType *p;
    for(p=&(L->elem[L->length-1]);p>=q;p--) *(p+1) = *p; //插入位置及之后的元素右移
    *q = e; //把e插入q的位置
    L->length++;
    return OK;
}
Status ListDelete(SqList *L,int i, ElemType *e){
    if(i<1 || i>L->length) return ERROR;
    ElemType *p = &(L->elem[i-1]); //p为删除位置
    *e = *p;
    ElemType *q = L->elem + L->length-1;
    for(++p; p<=q; p++) *(p-1) = *p;
    --L->length;
    return OK;
}
Status TraverseList(SqList *L){
    int i;
    if(L->length ==0){
        printf("\t线性表为空\n");
        return ERROR;
    }else{
        printf("该线性表为：");
        for(i=0;i<=L->length;i++){
            printf("%d ,",L->elem[i-1]);
        }
        printf("\n\n");
    }
    return OK;
}







