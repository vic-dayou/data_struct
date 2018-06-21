#include <stdio.h>
#include <stdlib.h>
/***********������������Binary Sort Tree��**********************/
/****
    ����������������һ�ſ��������߾����������ʵĶ�����
    ��1����������������Ϊ�գ��������������нڵ��ֵ��С�����ĸ�����ֵ
    ��2����������������Ϊ�գ��������������н���ֵ���������ĸ�����ֵ
    ��3��������������Ҳ�ֱ��Ƕ���������
****/
#define FALSE 0
#define TRUE 1
typedef int Status;
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

/*�ڸ�ָ��T��ָ�����������еݹ�Ĳ�����ؼ��ֵ���key������Ԫ��
�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE
����ָ��pָ�����·���Ϸ��ʵ����һ����㣬������FALSE
ָ��preָ��T��˫�ף����ʼֵΪNULL
*/
Status SearchBST(BiTree T, int key,BiTree pre, BiTree *p)
{
     if(!T)                     //���Ҳ��ɹ�
     {
         *p = pre;             //�������Ϊ�����������ǾͰ�ǰһ��Ԫ��ָ��pre����ʱΪNULL�����Ƹ�p��ע����Ϊ��ʱ��p��ΪNULL��
         return FALSE;         //���ؼ�û���ҵ�
     }
     else if(key == T->data)       //���ҳɹ�
     {
         *p=T;                           //�ҵ��˾Ͱ�Ŀ��Ԫ��ָ���p
         return TRUE;
     }
     else if(key < T->data)
     {
         return SearchBST(T->lchild,key,T,p) ;//����������������
     }
     else
     {
         return SearchBST(T->rchild,key,T,p);//����������������
     }
}
//����
Status InsertBTS(BiTree *T, int key)
{
    BiTree p;
    if(!SearchBST(*T,key,NULL,&p))
    {
        BiTree temp = (BiTree)malloc(sizeof(BiTNode));
        temp->data = key;
        temp->lchild = temp->rchild = NULL;
        if(!p)         //ֻ������Ϊ�յ������p==NULL
        {
            *T = temp;      // temp������Ϊ���ڵ�
        }else if(key < p->data)
        {
            p->lchild = temp;            // temp������Ϊ����
        }else
        {
            p->rchild = temp;              //temp������Ϊ�Һ���
        }
        return TRUE;
    }else
    {
        return FALSE;                   //s�����Ѿ��йؼ�����ͬ�Ľ�㣬���ٲ���
    }

}
//�������ʵ�ִ�С��������
void InorderReverse(BiTree T)
 {
     if(T)
     {
         InorderReverse(T->lchild);
         printf("%d ",T->data);
         InorderReverse(T->rchild);
     }
 }
/**
ɾ����Ϊ���������
1��ɾ�������Ҷ�ӽ�㣬ֱ��ɾ������
2��ɾ�����ֻ����������������������ֻҪ��ɾ���������������������ƶ���ɾ����㼴��
3��ɾ�����ͬʱ����������������Ҫ�ҵ�ɾ�����p��ֱ��ǰ������ֱ�Ӻ�̣���s����s������p��Ȼ��ɾ�����s
**/
Status DeleteBST(BiTree *T, int key)
//������������T�д��ڹؼ��ֵ���key�Ľ�㣬��ɾ���ý�㲢����TRUE ���򷵻�FALSE
{
    if(!T) return FALSE;
    else
    {
        if(key == (*T)->data)
        {
            return Delete(&(*T));
        }else if(key < (*T)->data)
        {
            return DeleteBST(&(*T)->lchild, key);
        }else
        {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
    return TRUE;
}

Status Delete(BiTree *T)
{
    BiTree q ,s;
    if((*T)->rchild == NULL)         //������Ϊ�գ�ֻ��Ҫ�ؽ�����������
    {
        q = *T;
        *T = (*T)->lchild;
        free(q);
    }
    else if((*T)->lchild == NULL)   // ������Ϊ�գ���ֻ��Ҫ�ؽ�����������
    {
        q = *T;
        *T = (*T)->rchild;
        free(q);
    }
    else                            //������������Ϊ��
    {
        q = *T;
        s = (*T)->lchild;
        while(s->rchild)           //һֱ���ң�ֱ���ҵ�ɾ������ֱ��ǰ��
        {
            q = s;
            s = s->rchild;
        }
        (*T)->data = s->data;      //��ʱsָ��ɾ������ǰ������ǰ��������Ԫ�ظ�ֵ��ɾ����㣬����ͷ�s
        if(q != *T)
        {
            q->rchild = s->lchild;

        }
        else
        {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return TRUE;

}
int main()
{
    int i;
    BiTree T = NULL ;
    int key[10] = {32,34,54,21,76,54,23,99,78,45};
    for (i=0; i<10; i++)
    {
        InsertBTS(&T,key[i]);
    }
    InorderReverse(T);
    DeleteBST(&T,78);
    printf("\n");
    InorderReverse(T);
    return 0;
}
