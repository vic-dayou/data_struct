#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
/*
    双向循环链表
相比较于单向循环链表只是多了一个指向前驱节点的指针

*/
typedef struct CirLNode{
    int data;
    int length;
    struct CirLNode *prior;
    struct CirLNode *next;
}CirLNode, *CirLinked;
//初始化一个空节点
CirLinked Init_CL();
//在循环链表中插入节点
int Insert_CL(CirLinked linked,int index,int e);
//通过索引index获取节点
CirLinked Local_CL(CirLinked linked,int index);
//初始化一个指定节点长度的循环链表
CirLinked Create_CL(int n);
//删除index处的元素，并将结果返回给*e
int Delete_CL(CirLinked linked, int index, int *e);
//获得index处节点元素
CirLinked Local_CL(CirLinked linked,int index);
//遍历循环整个链表
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
    //创建一个head
    CirLinked head = (CirLinked)malloc(sizeof(CirLinked));
    head->next = NULL;
    head->prior = NULL;
    head->length = 1;
    head->data = 0;
    int i=1;
    CirLinked temp = head;
    while(i<=n){
            //首先将链表初始化为一个双向非循环链表
        CirLinked s = (CirLinked)malloc(sizeof(CirLinked));
        s->next = temp->next;
        s->data = i;
        s->prior = temp;
        temp->next = s;
        temp = s;
        i++;
    }
    //将最后一个节点的next指向head->next,使head->next作为第一个元素，最后释放head构成循环链表
    temp->next = head->next;
    head->next->prior = temp;
    free(head);
    return temp->next; //返回的是第一个节点元素
    //return temp;   //返回最后一个节点元素
}



int Insert_CL(CirLinked linked,int index,int e){
    //判断linked节点是否为第一个节点，如果是则直接在其后插入
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
        //如果不是第一个节点,找到待插入节点位置
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
