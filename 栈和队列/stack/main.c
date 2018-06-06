#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_INIT_SIZE 100 //栈初始化分配空间
#define STACKINCREMENT 10   // 存储空间分配增量
#define OK 1
#define ERROR 0
typedef int SElemType;
typedef int Status;
typedef struct Stack{
    SElemType *base;     //在栈构造之前和销毁之后，base的值为NULL
    SElemType *top;       //栈顶指针
    int stacksize;       // 当前已分配的存储空间，以元素为单位
}SqStack;

//构造一个空栈
Status InitStack(SqStack *stack);
//若栈不为空，则用e返回栈顶元素，并返回OK，否则返回ERROR；
Status GetTop(SqStack *stack,SElemType *e);
//在栈顶插入新的元素e
Status Push(SqStack *stack, SElemType *e);
//若栈不为空则删除栈顶元素，用e返回其值，并返回OK，否则返回ERROR
Status Pop(SqStack *stack, SElemType *e);
//判断栈是否为空
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
    if(stack->top - stack->base >= stack->stacksize){ //栈满，追加存储空间
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
void Decimal_To_Octal(){ //十进制转八进制
    //对于输入的任意一个非负十进制整数，打印输出其等值的八进制数
    SqStack stack;
    int number,e,mod;
    InitStack(&stack);
    printf("输入一个非负十进制整数");
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
void Binary_To_Decimal(){ //二进制转十进制
    SqStack stack;
    InitStack(&stack);
    char c;
    int intc,e,sum=0;
    printf("请输入二进制数,#结束 ");
    scanf("%c",&c);
    while(c != '#'){
        intc = c - '0'; //把char类型字符串转换成int类型
        Push(&stack,&intc);
        scanf("%c",&c);
    }
    getchar();
    printf("栈的容量大小：%d",GetLength(stack));
    for(int i=0; !StackEmpty(stack); i++){
        Pop(&stack,&e);
        sum += e*pow(2,i);
    }
    printf("十进制数是：%d",sum);

}
int main()
{
    Binary_To_Decimal();
    return 0;
}
