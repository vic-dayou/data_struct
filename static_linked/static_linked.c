#include <stdio.h>
#define MAXSIZE 100 //链表的最大长度
/*******************************
                静态链表
数据结构：每个数组节点都有值和游标.
游标表示下一个节点，节点分为已用节点和备用节点
第一个节点和最后节点保留：
第一个节点游标表示备用节点起始位置
最后一个节点游标表示已用节点的起始位置
已用节点的最后一个元素的游标指向0，表示末尾。
*******************************/
typedef struct{
    int data;
    int cur;
}component,SLinkList[MAXSIZE];
//初始化静态链表
void InitSpace_SL(SLinkList space);
//从备用节点申请一个节点
int Malloc_SL(SLinkList space);
//释放节点,相当于free()
void Free_SL(SLinkList space,int k);
//初始化一个num数量的可用链表
Create_SL(SLinkList space, int num);
//在第index节点前插入一个节点
Insert_SL(SLinkList space, int index, int e);
//删除第index个节点，并将data输出到e
Delete_SL(SLinkList space, int index, int *e);
void InitSpace_SL(SLinkList space){
    //将一维数组space中各分量链成一个备用链表，space[0].cur为头指针
    int i;
    for (i=0; i<MAXSIZE-1; ++i){
        space[i].cur = i+1;
    }
    space[MAXSIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList space){
    //从备用链表中取出可用的节点
    int i = space[0].cur;
    if (space[0].cur) space[0].cur = space[i].cur;
    return i;
}

void Free_SL(SLinkList space,int k){
    //释放下标为k的节点，既是将space[0].cur=k,加入备用链表
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int Create_SL(SLinkList space,int num){
    //随机添加节点
    srand(time(0));
    int i,mov = MAXSIZE - 1;
    space[mov].cur = 1;
    for (i=0;i<num;i++){
        mov = space[mov].cur;
        space[mov].data = rand()%100+1;
    }
    space[0].cur = space[mov].cur; //移动备用节点的游标
    space[mov].cur = 0; //表示这个节点为可用节点的最后一个节点
    return 1;
}

void Traverse_SL(SLinkList space){
    //遍历输出静态链表
    int i = space[MAXSIZE - 1].cur;
    while (i)
    {
        printf("data[%d]=%d\t",i,space[i].data);
        i = space[i].cur;
    }
}

int Insert_SL(SLinkList space,int index,int e){
    int i = Malloc_SL(space);
    int mov = space[MAXSIZE - 1].cur; //找到第一个节点的下角标
    for( int j=1; j<index-1; j++){    //遍历找到要插入节点位置
        mov = space[mov].cur;
    }
    space[i].cur = space[mov].cur;
    space[i].data = e;
    space[mov].cur = i;
    return 1;

}
//删除位置节点，并将结果返回给e
int Delete_SL(SLinkList space,int index, int *e){
    int mov = space[MAXSIZE - 1].cur;
    for(int j=1;j<index-1;j++){ //将游标移动到index前一个节点
        mov = space[mov].cur;
    }
    int k = space[mov].cur;
    *e = space[k].data;
    printf("\nspace[%d].data =  %d\n",k,*e);
    space[mov].cur = space[k].cur;
    space[k].cur = 0;
    Free_SL(space,k);
    return 1;

}
 int Length_SL(SLinkList space){
    int length = 0;
    int move = space[MAXSIZE - 1].cur;
    while(move){
        move = space[move].cur;
        length++;
    }
    return length;
 }




