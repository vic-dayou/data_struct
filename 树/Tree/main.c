#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define ERROR 0;
typedef int Status;
typedef int TElemType;

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;


//创建一个完全二叉树
BiTNode * CreateBiTree(int i, int n)
{
    /*
        n是完全二叉树的节点数，则节点按层序编号（从左到右），则对任一节点 i 有：
        （1）如果 i = 1，则节点 i 是二叉树的根，无双亲；如果 i > 1 则双亲PARENT(i)是节点 (i/2)向下取整
        （2）如果 2i > n,则节点 i 无左孩子（即 i 为叶子节点）；否则其左孩子为LCHILD(i)是节点2i
        （3）如果 2i + 1 > n,则节点 i 无右孩子，否则其右孩子RCHILD(i) 是节点 2i+1
    */
    BiTNode *root = (BiTNode *)malloc(sizeof(BiTNode));
    root->data = i;
    if(2*i <= n)
    {
        root->lchild = CreateBiTree(2*i,n);
    }
    else
    {
        root->lchild = NULL;
    }
    if(2*i+1 <= n)
    {
        root->rchild = CreateBiTree(2*i+1,n);
    }
    else
    {
        root->rchild = NULL;
    }
    return root;
}

//按先序序列建立二叉树
BiTree CreateBiTree2(BiTree T)
{
    char c ;
    scanf("%c",&c);
    if(' ' ==  c)
    {
        T = NULL;
    }
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T) exit(-1);
        T->data = c;
        CreateBiTree2(T->lchild);
        CreateBiTree2(T->rchild);
    }
    return T;
}
//前序遍历
int PreOrderTraverse(BiTNode *T)
{
    /*
    (1) 先访问根节点
    (2) 先序遍历左子树
    (3) 先序遍历右子树
    */
    printf("%d ",T->data);
    if(T->lchild != NULL)
    {
        PreOrderTraverse(T->lchild);
    }

    if(T->rchild != NULL)
    {
        PreOrderTraverse(T->rchild);
    }
    return 0;
}


//中序遍历
int InOrderTraverse(BiTNode *T)
{
    /*
    (1) 中序遍历左子树
    (2) 访问根节点
    (3) 中序遍历右子树

    */

    if(T->lchild != NULL)
    {
        InOrderTraverse(T->lchild);
    }
    printf("%d ",T->data);
    if(T->rchild != NULL)
    {
        InOrderTraverse(T->rchild);
    }

    return 1;
}

//后序遍历
int PostOrderTraverse(BiTNode *T)
{
    /*
        (1) 后序遍历左子树
        (2) 后序遍历右子树
        (3) 访问根节点
    */


    if(T->lchild != NULL)
    {
        PostOrderTraverse(T->lchild);
    }
    if(T->rchild != NULL)
    {
        PostOrderTraverse(T->rchild);
    }
    printf("%d ",T->data);
    return 1;
}

int main()
{
    BiTNode *root = CreateBiTree(1,8);
    PreOrderTraverse(root);
    printf("\n");
    InOrderTraverse(root);
    printf("\n");
    PostOrderTraverse(root);
    return 0;
}

