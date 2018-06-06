#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
/*
    ˫��ѭ������
��Ƚ��ڵ���ѭ������ֻ�Ƕ���һ��ָ��ǰ���ڵ��ָ��

*/
typedef struct CirLNode{
    int data;
    int length;
    struct CirLNode *prior;
    struct CirLNode *next;
}CirLNode, *CirLinked;
//��ʼ��һ���սڵ�
CirLinked Init_CL();
//��ѭ�������в���ڵ�
int Insert_CL(CirLinked linked,int index,int e);
//ͨ������index��ȡ�ڵ�
CirLinked Local_CL(CirLinked linked,int index);
//��ʼ��һ��ָ���ڵ㳤�ȵ�ѭ������
CirLinked Create_CL(int n);
//ɾ��index����Ԫ�أ�����������ظ�*e
int Delete_CL(CirLinked linked, int index, int *e);
//���index���ڵ�Ԫ��
CirLinked Local_CL(CirLinked linked,int index);
//����ѭ����������
void Traversal(CirLinked linked);


CirLinked Init_CL(){
   CirLinked linked = (CirLinked)malloc(sizeof(CirLinked));
    if(linked){
        linked->next = NULL;
        linked->prior = NULL;
        linked->length = 0;
    }else{
        printf("malloc new failed");
        exit(-1);
    }
    return linked;
}
CirLinked Create_CL(int n){
    //����һ��head
    CirLinked head = (CirLinked)malloc(sizeof(CirLinked));
    head->next = NULL;
    head->prior = NULL;
    head->length = 1;
    head->data = 0;
    int i=1;
    CirLinked temp = head;
    while(i<=n){
            //���Ƚ������ʼ��Ϊһ��˫���ѭ������
        CirLinked s = (CirLinked)malloc(sizeof(CirLinked));
        s->next = temp->next;
        s->data = i;
        s->prior = temp;
        temp->next = s;
        temp = s;
        i++;
    }
    //�����һ���ڵ��nextָ��head->next,ʹhead->next��Ϊ��һ��Ԫ�أ�����ͷ�head����ѭ������
    temp->next = head->next;
    head->next->prior = temp;
    free(head);
    return temp->next; //���ص��ǵ�һ���ڵ�Ԫ��
    //return temp;   //�������һ���ڵ�Ԫ��
}



int Insert_CL(CirLinked linked,int index,int e){
    //�ж�linked�ڵ��Ƿ�Ϊ��һ���ڵ㣬�������ֱ����������
   // printf("here....%d",linked->length);
    if(!linked->next){
        //    printf("here");
        CirLinked s = Init_CL();
        s->data = e;
        s->length = linked->length + 1;
        s->next = linked;
        s->prior = linked;
        linked->next = s;
        linked->prior = s;
        return OK;
    }else{
        //������ǵ�һ���ڵ�,�ҵ�������ڵ�λ��
      CirLinked p = Local_CL(linked,index);
      //printf("****==%d",p->length);
      CirLinked s = Init_CL();
    //  printf("+++++++++==%d",s->length);
      s->data = e;
      s->prior = p->prior;
      s->next = p;
      p->prior->next = s;
      p->prior = s;
      return OK;
    }

}
int Delete_CL(CirLinked linked, int index, int *e){
    if(!linked) return ERROR;
    CirLinked p = Local_CL(linked,index);
    e = p->data;
    p->next->prior = p->prior;
    p->prior->next = p->next;
    return e;

}
CirLinked Local_CL(CirLinked linked,int index){
    if(!linked) return ERROR;
    CirLinked p = linked;
    for(int i=1;i<index;i++){
        p = p->next;
        if(p == linked){
            break;
        }
    }
    return p;
}

void Traversal(CirLinked linked){
    if(!linked) return ERROR;
    CirLinked p = linked;
    int i=1;
    while(1){
         printf("data[%d]=%d\t",i,p->data);
         p = p->next;
         i++;
         if(p == linked) break;
    }
}
