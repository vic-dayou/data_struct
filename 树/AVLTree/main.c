#include <stdio.h>
#include <stdlib.h>
/***************ƽ�������(AVL Tree)****************************/
/*
    ƽ���������һ�ֶ�����������BST����������������
    1������������������������ƽ������������������������������֮��ľ���ֵ������1
    �����������Ͻ���ƽ������BF����Ϊ����������ȼ�ȥ����������ȣ�������ƽ��������ϵ�
    �ڵ��ƽ������BFֻ������ -1��0��1
*/
#define LH +1     /* ��� */
#define EH 0     /* �ȸ� */
#define RH -1     /* �Ҹ� */
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef struct BiTNode{
    int data;
    int bf;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/*����TΪ���Ķ�������������������*/
/*����֮��Tָ���µĸ���㣬����ת֮ǰ���������ĸ����*/
void R_Rotate(BiTree *T)
{
    BiTree L;
    L = (*T)->lchild;               //  Lָ��T�����������ڵ�
    (*T)->lchild = L->rchild;       //  L ���������ӵ�T��������
    L->rchild = (*T);               //  T��ΪL��������
    *T = L;                         // T����ָ����ڵ�
}
/*����TΪ���Ķ�������������������*/
/*����֮��T����ָ���µĸ��ڵ㣬����ת֮ǰ���������ĸ���� */
void L_Rotate(BiTree *T)
{
    BiTree R;
    R = (*T)->rchild;
    (*T)->rchild = R->lchild;
    R->lchild = (*T);
    *T = R;
}

/*  ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת���� */
void LeftBalance(BiTree *T)          //���Һ�����ת
{
    BiTree L, Lr;
    L = (*T)->lchild;         /* L ָ��T�������������*/

    switch(L->bf)
    {
    case LH:              /*�½�������T�����ӵ��������ϣ�������������*/
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    case RH:              /*�½�������T�����ӵ��������ϣ���˫������*/
        Lr = L->rchild;   /* Lrָ��T�����ӵ������������*/
        switch(Lr->bf)    /* �޸�T�������ӵ�ƽ������*/
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
        L_Rotate(&(*T)->lchild);    /* ��T��������������ƽ�⴦��*/
        R_Rotate(T);                /* ��T������ƽ�⴦��*/
    }
}

void RightBalance(BiTree *T)     //���������ת
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
    ����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����
    ����Ԫ��Ϊe���½�㲢����1�����򷵻�0.��������ʹ����������ʧȥƽ��
    ����ƽ����ת������������taller��ӦT�������
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
                switch((*T)->bf)      //�����ԭ����ƽ�����ӣ�����ֵ 1��0��-1
                {
                case LH:               // ԭ��ֵΪ1�������֮��ͱ����2����Ҫ������ƽ�⴦��
                    LeftBalance(&(*T));
                    *taller = FALSE;
                    break;
                case EH:                //  ԭ��ֵΪ0�������֮����1����ȼ�+1
                    (*T)->bf = LH;
                    *taller = TRUE;
                    break;
                case RH:               // ԭ��ֵΪ-1������������������������������ͬ��ƽ������Ϊ0
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
