#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 64
#define STACKINCREMENT 16
/***************�������ṹ��*****************************/
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
/*****************��Ŷ������ڵ��ջ*********************/
typedef struct TreeStack{
    BiTree *base;
    BiTree *top;
    int stacksize;
}TrStack;

/************************ջ*********************************/
int InitStack(TrStack *stack)
{
    stack->base = (BiTree *)malloc(STACK_INIT_SIZE * sizeof(BiTNode));
    if(!stack->base) exit(-1);
    stack->top = stack->base;
    stack->stacksize = STACK_INIT_SIZE;
    return 0;
}
int Push(TrStack *stack, BiTree e){
    if(stack->top - stack->base >= stack->stacksize){ //ջ����׷�Ӵ洢�ռ�
        stack->base = (BiTree *)realloc(stack->base,(stack->stacksize+STACKINCREMENT)*sizeof(BiTNode));
        if(!stack->base) exit(-1);
        stack->top = stack->base + stack->stacksize;
        stack->stacksize += STACKINCREMENT;
    }
    *(stack->top++) = e;
    return 0;

}
int Pop(TrStack *stack,BiTree *e){
    if(stack->base == stack->top) exit(0);
    *e =  *(--stack->top);
    return 1;
}

int StackEmpty(TrStack stack){
    if(stack.base == stack.top){
        return 1;
    }else{
        return 0;
    }
}

int GetTop(TrStack stack, BiTree *e){
    if(StackEmpty(stack)) exit(0);
    *e = *(stack.top-1);
    return 1;
}

/******************��********************************/
int CreateBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);
    if(' ' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!T){
            printf("FAILD");
            exit(0);
        };
        (*T)->data = c;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    return 1;
}
//�������
int InOrderTraversal2(BiTree T)
{
    if(T)
    {
        InOrderTraversal2(T->lchild);
        printf("%c",T->data);
        InOrderTraversal2(T->rchild);
    }
    return 1;
}
//�ǵݹ��������
int InOrderTraversal(BiTree T)
{
    TrStack S;
    InitStack(&S);
    Push(&S,T);
    while(!StackEmpty(S))
    {
        BiTree temp = NULL;
        while(GetTop(S,&temp) && temp) //�����ߵ���ͷ
        {
            Push(&S,temp->lchild);
        }
        Pop(&S,&temp); //�ѿսڵ㵯��ȥ


        if(!StackEmpty(S))//���ʽڵ㣬����һ��
        {
            Pop(&S,&temp);
            printf("%c",temp->data);
            Push(&S,temp->rchild);
        }
    }
    //�ͷ�ջ
    return 1;
}

int main()
{

    BiTree T = NULL;
    CreateBiTree(&T);
    InOrderTraversal2(T);
    printf("\n");
    InOrderTraversal(T);
    return 0;
}
