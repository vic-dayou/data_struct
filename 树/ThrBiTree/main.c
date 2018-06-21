#include <stdio.h>
#include <stdlib.h>
#include<memory.h>
/****************线索二叉树*******************************/
typedef char TElemType;
typedef enum PointerTag{
    Link, Thread
}PointerTag; // Link == 0:指针，Thread == 1:线索；

typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild, *rchild; //左右孩子指针
    PointerTag LTag, RTag; // LTag == Thread时表示左子树为线索，记录直接前驱
}BiThrNode, *BiThrTree;

//全局变量，始终指向刚访问过的结点、
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
    *Thrt = (BiThrTree)malloc(sizeof(BiThrNode)); //创建头结点，并对其初始化
     //bzero(&Thrt,sizeof(Thrt));
    if(!Thrt) exit(-1);
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = *Thrt;  //右指针回指

    if(!T) (*Thrt)->lchild = *Thrt; // 若二叉树为空，则左指针回指
    else
    {
        (*Thrt)->lchild = T;
        pre = *Thrt;
        InThreading(T); // 中序遍历进行线索化
        pre->rchild = Thrt; pre->RTag = Thread; // 最后一个结点线索化
        (*Thrt)->rchild = pre;
    }
}

void InThreading(BiThrTree p) //中序遍历使其线索化
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
//中序遍历线索化的二叉树
void InOrderTraversal_Thr(BiThrTree T)
{
    BiThrTree p= T->lchild; //p 为二叉树中的第一个结点
    while(p != T)
    {
       while(p->LTag == Link) // 一直走到左子树的最后一个叶子
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
