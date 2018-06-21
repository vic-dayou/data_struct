#include <stdio.h>
#include <stdlib.h>
#include<memory.h>
/****************����������*******************************/
typedef char TElemType;
typedef enum PointerTag{
    Link, Thread
}PointerTag; // Link == 0:ָ�룬Thread == 1:������

typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild, *rchild; //���Һ���ָ��
    PointerTag LTag, RTag; // LTag == Threadʱ��ʾ������Ϊ��������¼ֱ��ǰ��
}BiThrNode, *BiThrTree;

//ȫ�ֱ�����ʼ��ָ��շ��ʹ��Ľ�㡢
BiThrTree pre=NULL;

BiThrNode* CreateBiTree(int i, int n)
{
    BiThrNode *root = (BiThrNode *)malloc(sizeof(BiThrNode));
   // bzero(&root,sizeof(root));
    root->data = i;
    root->LTag = Link;
    root->RTag = Link;
    if(2*i <= n)
    {
        root->lchild = (BiThrNode *)CreateBiTree(2*i,n);
    }
    else
    {
        root->lchild = NULL;
    }
    if(2*i+1 <= n)
    {
        root->rchild  = (BiThrNode *)CreateBiTree(2*i+1,n);
    }
    else
    {
        root->rchild = NULL;
    }
    return root;
}

void InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{
    *Thrt = (BiThrTree)malloc(sizeof(BiThrNode)); //����ͷ��㣬�������ʼ��
     //bzero(&Thrt,sizeof(Thrt));
    if(!Thrt) exit(-1);
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = *Thrt;  //��ָ���ָ

    if(!T) (*Thrt)->lchild = *Thrt; // ��������Ϊ�գ�����ָ���ָ
    else
    {
        (*Thrt)->lchild = T;
        pre = *Thrt;
        InThreading(T); // �����������������
        pre->rchild = Thrt; pre->RTag = Thread; // ���һ�����������
        (*Thrt)->rchild = pre;
    }
}

void InThreading(BiThrTree p) //�������ʹ��������
{
    if(p)
    {

        InThreading(p->lchild);
        if(!p->lchild)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild)
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}
//��������������Ķ�����
void InOrderTraversal_Thr(BiThrTree T)
{
    BiThrTree p= T->lchild; //p Ϊ�������еĵ�һ�����
    while(p != T)
    {
       while(p->LTag == Link) // һֱ�ߵ������������һ��Ҷ��
        {
            p = p->lchild;
        }
        printf("%d",p->data);

        while(p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            printf("%d",p->data);

        }
        p = p->rchild;

    }

}
int main()
{
    BiThrTree root = CreateBiTree(1,8);
    BiThrTree Thrt;
    InOrderThreading(&Thrt,root);
    InOrderTraversal_Thr(Thrt);
    return 0;
}
