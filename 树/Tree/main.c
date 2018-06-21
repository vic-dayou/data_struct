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


//����һ����ȫ������
BiTNode * CreateBiTree(int i, int n)
{
    /*
        n����ȫ�������Ľڵ�������ڵ㰴�����ţ������ң��������һ�ڵ� i �У�
        ��1����� i = 1����ڵ� i �Ƕ������ĸ�����˫�ף���� i > 1 ��˫��PARENT(i)�ǽڵ� (i/2)����ȡ��
        ��2����� 2i > n,��ڵ� i �����ӣ��� i ΪҶ�ӽڵ㣩������������ΪLCHILD(i)�ǽڵ�2i
        ��3����� 2i + 1 > n,��ڵ� i ���Һ��ӣ��������Һ���RCHILD(i) �ǽڵ� 2i+1
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

//���������н���������
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
//ǰ�����
int PreOrderTraverse(BiTNode *T)
{
    /*
    (1) �ȷ��ʸ��ڵ�
    (2) �������������
    (3) �������������
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


//�������
int InOrderTraverse(BiTNode *T)
{
    /*
    (1) �������������
    (2) ���ʸ��ڵ�
    (3) �������������

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

//�������
int PostOrderTraverse(BiTNode *T)
{
    /*
        (1) �������������
        (2) �������������
        (3) ���ʸ��ڵ�
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

