#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_INIT_SIZE 100 //ջ��ʼ������ռ�
#define STACKINCREMENT 10   // �洢�ռ��������
#define OK 1
#define ERROR 0
typedef int SElemType;
typedef int Status;
typedef struct Stack{
    SElemType *base;     //��ջ����֮ǰ������֮��base��ֵΪNULL
    SElemType *top;       //ջ��ָ��
    int stacksize;       // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

//����һ����ջ
Status InitStack(SqStack *stack);
//��ջ��Ϊ�գ�����e����ջ��Ԫ�أ�������OK�����򷵻�ERROR��
Status GetTop(SqStack *stack,SElemType *e);
//��ջ�������µ�Ԫ��e
Status Push(SqStack *stack, SElemType *e);
//��ջ��Ϊ����ɾ��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
Status Pop(SqStack *stack, SElemType *e);
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack stack);
Status InitStack(SqStack *stack)
{
    stack->base = (SElemType * )malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!stack->base) exit(-1);
    stack->top = stack->base;
    stack->stacksize = STACK_INIT_SIZE;
    return OK;
}
Status GetTop(SqStack *stack,SElemType *e){
    if(stack->base == stack->top) return ERROR;
    e = (stack->top-1);
    return OK;
}
Status Push(SqStack *stack, SElemType *e){
    if(stack->top - stack->base >= stack->stacksize){ //ջ����׷�Ӵ洢�ռ�
        stack->base = (SElemType * )realloc(stack->base,(stack->stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!stack->base) exit(-1);
        stack->top = stack->base + stack->stacksize;
        stack->stacksize += STACKINCREMENT;
    }
    *stack->top++ = *e;
    return OK;

}
Status StackEmpty(SqStack stack){
    if(stack.base == stack.top){
        return OK;
    }else{
        return ERROR;
    }
}

Status Pop(SqStack *stack, SElemType *e){
    if(stack->base == stack->top) return ERROR;
    *e =  *(--stack->top);
    return OK;
}

int GetLength(SqStack stack){
    int len = (stack.top - stack.base);
    return len;
}
void Decimal_To_Octal(){ //ʮ����ת�˽���
    //�������������һ���Ǹ�ʮ������������ӡ������ֵ�İ˽�����
    SqStack stack;
    int number,e,mod;
    InitStack(&stack);
    printf("����һ���Ǹ�ʮ��������");
    scanf("%d",&number);
    while (number)
    {   mod = number % 8;
        Push(&stack,&mod);
        number = number/8;
    }

    while (!StackEmpty(stack))
    {
        Pop(&stack,&e);
        printf("%d",e);
    }
}
void Binary_To_Decimal(){ //������תʮ����
    SqStack stack;
    InitStack(&stack);
    char c;
    int intc,e,sum=0;
    printf("�������������,#���� ");
    scanf("%c",&c);
    while(c != '#'){
        intc = c - '0'; //��char�����ַ���ת����int����
        Push(&stack,&intc);
        scanf("%c",&c);
    }
    getchar();
    printf("ջ��������С��%d",GetLength(stack));
    for(int i=0; !StackEmpty(stack); i++){
        Pop(&stack,&e);
        sum += e*pow(2,i);
    }
    printf("ʮ�������ǣ�%d",sum);

}
int main()
{
    Binary_To_Decimal();
    return 0;
}
