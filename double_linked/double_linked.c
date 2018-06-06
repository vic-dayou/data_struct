#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define ERROR 0
#define OK 1
/*
    ˫������
˫������������ָ��*prior��*next�����Ƿֱ�ָ�������ֱ��ǰ����ֱ�Ӻ��
ͷ����ֱ��ǰ��ΪNULL
β�ڵ��ֱ�Ӻ��ΪNULL
���ǿ��Դ�һ���ڵ�˫��ķ�������

*/
typedef struct DuLNode{
    unsigned int data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;
//��ʼ��˫������
int Init_DL(DuLinkList linked);
//��������
void TraverseLinked(DuLinkList linked);
//����Ԫ��
int Insert_DL(DuLinkList linked,int index,int e);
//�h��Ԫ�ز����h��Ԫ�ط��ؽoe
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
//�жϵ�ǰ�����Ƿ�ֻ��һ��ͷ��㣬����ֻ��һ��ͷ��㣬����indexΪ��ֵ������ͷ���������һ��Ԫ��
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
   //���ɾ�����������е����һ��
    if(!Local_DL(linked,index))
    {   printf("index �Ƿ�");
        return ERROR; //index�Ƿ�
    }
    DuLinkList p = linked->next;
    if (!(p->next)){
        p->prior->next = p->next;
        free(p);
        return OK;
    }
    //����������һ�������ҵ���ɾ��λ��
    for (int i=1; i<index; i++){
        p = p->next;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

void TraverseLinked(DuLinkList linked){
    //linked��Ϊͷ��㲻�������
    DuLinkList p = linked->next;
    while(p){
        printf("-->%d\t",p->data);
        p = p->next;
    }

}
