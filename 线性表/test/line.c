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

/*��ʼ��һ���յ����Ա�*/
//Status InitList(SqList *L);
/*�������Ա�*/
//void DestroyList(SqList *L);
/*�ÿ����Ա�*/
//void clearList(SqList *L);
/*�ж����Ա��Ƿ�Ϊ��*/
//Status ListEmpty(SqList *L)
/*��e����L�е�i������Ԫ�ص�ֵ*/
//Status GetElem(SqList *L,int i,ElemType *e);
/*��ȡԪ��cur_e��ֱ��ǰ��*/
//Status PriorElem(SqList *L,ElemType cur_e,ElemType *prior_e);
/*��ȡԪ��cur_e��ֱ�Ӻ��*/
//Status NextElem(SqList *L,ElemType cur_e,ElemType *next_e);
/*��λ��i��ǰ���������Ԫ��*/
//Status ListInsert(SqList *L,int i,ElemType e);
/*ɾ��λ��i��������Ԫ�ط��ظ�e*/
//Status ListDelete(SqList *L,int i,ElemType *e);
/*�����Ա�������Ԫ�ؽ�������,��С����*/
//void ListSort_SqList(SqList *L);
/*�������Ա��е���������Ԫ��*/
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
        L->elem=NULL;   //�ͷ����Ա��ڴ�ռ�
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
    if(cur_e == L->elem[0]) return ERROR;    //��һ��Ԫ��û��ֱ��ǰ��
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
    if(cur_e == L->elem[L->length-1]) return ERROR; //���һ��Ԫ��û��ֱ�Ӻ��
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
    if(i<1 || i>L->length) return ERROR; //iֵ���Ϸ�
    if(L->length >= L->listsize) { //��ǰ�ڴ����������ӷ���
        ElemType *newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(! newbase) exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    ElemType *q = &(L->elem[i-1]); //qΪ����λ��
    ElemType *p;
    for(p=&(L->elem[L->length-1]);p>=q;p--) *(p+1) = *p; //����λ�ü�֮���Ԫ������
    *q = e; //��e����q��λ��
    L->length++;
    return OK;
}
Status ListDelete(SqList *L,int i, ElemType *e){
    if(i<1 || i>L->length) return ERROR;
    ElemType *p = &(L->elem[i-1]); //pΪɾ��λ��
    *e = *p;
    ElemType *q = L->elem + L->length-1;
    for(++p; p<=q; p++) *(p-1) = *p;
    --L->length;
    return OK;
}
Status TraverseList(SqList *L){
    int i;
    if(L->length ==0){
        printf("\t���Ա�Ϊ��\n");
        return ERROR;
    }else{
        printf("�����Ա�Ϊ��");
        for(i=0;i<=L->length;i++){
            printf("%d ,",L->elem[i-1]);
        }
        printf("\n\n");
    }
    return OK;
}







