#include <stdio.h>
#include <stdlib.h>
/***********二叉排序树（Binary Sort Tree）**********************/
/****
    二叉排序树或者是一颗空树，或者具有下列性质的二叉树
    （1）若它的左子树不为空，则左子树上所有节点的值均小于它的根结点的值
    （2）若它的右子树不为空，则右子树上所有结点的值均大于它的根结点的值
    （3）它的左、右子树也分别是二叉排序树
****/
#define FALSE 0
#define TRUE 1
typedef int Status;
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

/*在根指针T所指二叉排序树中递归的查找其关键字等于key的数据元素
若查找成功，则指针p指向该数据元素结点，并返回TRUE
否则指针p指向查找路径上访问的最后一个结点，并返回FALSE
指针pre指向T的双亲，其初始值为NULL
*/
Status SearchBST(BiTree T, int key,BiTree pre, BiTree *p)
{
     if(!T)                     //查找不成功
     {
         *p = pre;             //如果此数为空树，那我们就把前一个元素指针pre（此时为NULL）复制给p，注意树为空时，p才为NULL。
         return FALSE;         //返回假没有找到
     }
     else if(key == T->data)       //查找成功
     {
         *p=T;                           //找到了就把目标元素指针给p
         return TRUE;
     }
     else if(key < T->data)
     {
         return SearchBST(T->lchild,key,T,p) ;//在左子树继续查找
     }
     else
     {
         return SearchBST(T->rchild,key,T,p);//在右子树继续查找
     }
}
//插入
Status InsertBTS(BiTree *T, int key)
{
    BiTree p;
    if(!SearchBST(*T,key,NULL,&p))
    {
        BiTree temp = (BiTree)malloc(sizeof(BiTNode));
        temp->data = key;
        temp->lchild = temp->rchild = NULL;
        if(!p)         //只有在树为空的情况下p==NULL
        {
            *T = temp;      // temp插入作为根节点
        }else if(key < p->data)
        {
            p->lchild = temp;            // temp插入作为左孩子
        }else
        {
            p->rchild = temp;              //temp插入作为右孩子
        }
        return TRUE;
    }else
    {
        return FALSE;                   //s树中已经有关键字相同的结点，不再插入
    }

}
//中序遍历实现从小到大排序
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
删除分为三种情况：
1，删除结点是叶子结点，直接删除即可
2，删除结点只有左子树或者右子树，则只要把删除结点的左子树或右子树移动到删除结点即可
3，删除结点同时存在左右子树，需要找到删除结点p的直接前驱（或直接后继）是s，用s来代替p，然后删除结点s
**/
Status DeleteBST(BiTree *T, int key)
//若二叉排序树T中存在关键字等于key的结点，则删除该结点并返回TRUE 否则返回FALSE
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
    if((*T)->rchild == NULL)         //右子树为空，只需要重接它的左子树
    {
        q = *T;
        *T = (*T)->lchild;
        free(q);
    }
    else if((*T)->lchild == NULL)   // 左子树为空，则只需要重接它的右子树
    {
        q = *T;
        *T = (*T)->rchild;
        free(q);
    }
    else                            //左右子树都不为空
    {
        q = *T;
        s = (*T)->lchild;
        while(s->rchild)           //一直向右，直到找到删除结点的直接前驱
        {
            q = s;
            s = s->rchild;
        }
        (*T)->data = s->data;      //此时s指向删除结点的前驱，将前驱的数据元素赋值给删除结点，最后释放s
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
