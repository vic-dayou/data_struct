#include <stdio.h>
#include <stdlib.h>
/***************平衡二叉树(AVL Tree)****************************/
/*
    平衡二叉树是一种二叉排序树（BST），具有以下性质
    1，它的左子树和右子树都是平衡二叉树，且左子树和右子树的深度之差的绝对值不超过1
    若将二叉树上结点的平衡因子BF定义为左子树的深度减去右子树的深度，则所有平衡二叉树上的
    节点的平衡因子BF只可能是 -1、0、1
*/
#define LH +1     /* 左高 */
#define EH 0     /* 等高 */
#define RH -1     /* 右高 */
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef struct BiTNode{
    int data;
    int bf;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/*对以T为根的二叉排序树做右旋处理*/
/*处理之后T指向新的根结点，即旋转之前的左子树的根结点*/
void R_Rotate(BiTree *T)
{
    BiTree L;
    L = (*T)->lchild;               //  L指向T的左子树根节点
    (*T)->lchild = L->rchild;       //  L 的右子树接到T的左子树
    L->rchild = (*T);               //  T成为L的右子树
    *T = L;                         // T重新指向根节点
}
/*对以T为根的二叉排序树做左旋处理*/
/*处理之后T重新指向新的根节点，即旋转之前的右子树的根结点 */
void L_Rotate(BiTree *T)
{
    BiTree R;
    R = (*T)->rchild;
    (*T)->rchild = R->lchild;
    R->lchild = (*T);
    *T = R;
}

/*  对以指针T所指结点为根的二叉树做左平衡旋转处理 */
void LeftBalance(BiTree *T)          //先右后左旋转
{
    BiTree L, Lr;
    L = (*T)->lchild;         /* L 指向T的左子树根结点*/

    switch(L->bf)
    {
    case LH:              /*新结点插入在T的左孩子的左子树上，做单右旋处理*/
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    case RH:              /*新结点插入在T的左孩子的右子树上，做双旋处理*/
        Lr = L->rchild;   /* Lr指向T的左孩子的右子树根结点*/
        switch(Lr->bf)    /* 修改T及其左孩子的平衡因子*/
        {
        case LH:
            (*T)->bf = RH;
            L->bf = EH;
            break;
        case EH:
            (*T)->bf = L->bf = EH;
            break;
        case RH:
            L->bf = LH;
            break;
        }

        Lr->bf = EH;
        L_Rotate(&(*T)->lchild);    /* 对T的左子树做左旋平衡处理*/
        R_Rotate(T);                /* 对T做右旋平衡处理*/
    }
}

void RightBalance(BiTree *T)     //先左后右旋转
{
    BiTree R, Rl;
    R = (*T)->rchild;

    switch(R->bf)
    {
    case RH:
        (*T)->bf = R->bf = EH;
        L_Rotate(T);
        break;
    case LH:
        Rl = R->lchild;
        switch(Rl->bf)
        {
        case LH:
            (*T)->bf = EH;
            R->bf = RH;
            break;
        case EH:
            (*T)->bf = R->bf = EH;
            break;
        case RH:
            (*T)->bf = LH;
            R->bf = EH;
            break;
        }

        Rl->bf = EH;
        R_Rotate(&(*T)->rchild);
        L_Rotate(T);
    }
}
/*
    若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入
    数据元素为e的新结点并返回1，否则返回0.若因插入而使二叉排序树失去平衡
    则做平衡旋转处理，布尔变量taller反应T长高与否。
*/
Status InsertAVL(BiTree *T,int e,Status *taller)
{
    if(!*T)
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else
    {
        if(e == (*T)->data)
        {
            *taller = FALSE;
            return FALSE;
        }
        else if(e < (*T)->data)
        {
            if(!InsertAVL(&(*T)->lchild,e,taller)) return FALSE;
            if(*taller)
            {
                switch((*T)->bf)      //根结点原来的平衡因子，可能值 1、0、-1
                {
                case LH:               // 原来值为1，则插入之后就变成了2，需要进行左平衡处理
                    LeftBalance(&(*T));
                    *taller = FALSE;
                    break;
                case EH:                //  原来值为0，则插入之后变成1，深度加+1
                    (*T)->bf = LH;
                    *taller = TRUE;
                    break;
                case RH:               // 原来值为-1，在左子树插入结点后，左右子树深度相同，平衡因子为0
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                }

            }
        }
        else
        {
            if(!InsertAVL(&(*T)->rchild,e,taller)) return FALSE;
            if(*taller)
            {
                switch((*T)->bf)
                {
                case LH:
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                case EH:
                    (*T)->bf = RH;
                    *taller = TRUE;
                    break;
                case RH:
                    RightBalance(&(*T));
                    *taller = FALSE;
                    break;
                }
            }
        }

    }
    return TRUE;
}

void InorderReverse(BiTree T)
{
     if(T)
     {
         InorderReverse(T->lchild);
         printf("%d(%d) ",T->data,T->bf);
         InorderReverse(T->rchild);
     }
}
int main()
{
    int i;
    int a[10] = {3,2,1,4,5,6,7,10,9,8};
    BiTree T = NULL;
    Status taller;
    for(i=0; i<10; i++)
    {
        InsertAVL(&T,a[i],&taller);
    }
    InorderReverse(T);
    return 0;
}
