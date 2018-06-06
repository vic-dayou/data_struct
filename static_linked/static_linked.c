#include <stdio.h>
#define MAXSIZE 100 //�������󳤶�
/*******************************
                ��̬����
���ݽṹ��ÿ������ڵ㶼��ֵ���α�.
�α��ʾ��һ���ڵ㣬�ڵ��Ϊ���ýڵ�ͱ��ýڵ�
��һ���ڵ�����ڵ㱣����
��һ���ڵ��α��ʾ���ýڵ���ʼλ��
���һ���ڵ��α��ʾ���ýڵ����ʼλ��
���ýڵ�����һ��Ԫ�ص��α�ָ��0����ʾĩβ��
*******************************/
typedef struct{
    int data;
    int cur;
}component,SLinkList[MAXSIZE];
//��ʼ����̬����
void InitSpace_SL(SLinkList space);
//�ӱ��ýڵ�����һ���ڵ�
int Malloc_SL(SLinkList space);
//�ͷŽڵ�,�൱��free()
void Free_SL(SLinkList space,int k);
//��ʼ��һ��num�����Ŀ�������
Create_SL(SLinkList space, int num);
//�ڵ�index�ڵ�ǰ����һ���ڵ�
Insert_SL(SLinkList space, int index, int e);
//ɾ����index���ڵ㣬����data�����e
Delete_SL(SLinkList space, int index, int *e);
void InitSpace_SL(SLinkList space){
    //��һά����space�и���������һ����������space[0].curΪͷָ��
    int i;
    for (i=0; i<MAXSIZE-1; ++i){
        space[i].cur = i+1;
    }
    space[MAXSIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList space){
    //�ӱ���������ȡ�����õĽڵ�
    int i = space[0].cur;
    if (space[0].cur) space[0].cur = space[i].cur;
    return i;
}

void Free_SL(SLinkList space,int k){
    //�ͷ��±�Ϊk�Ľڵ㣬���ǽ�space[0].cur=k,���뱸������
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int Create_SL(SLinkList space,int num){
    //�����ӽڵ�
    srand(time(0));
    int i,mov = MAXSIZE - 1;
    space[mov].cur = 1;
    for (i=0;i<num;i++){
        mov = space[mov].cur;
        space[mov].data = rand()%100+1;
    }
    space[0].cur = space[mov].cur; //�ƶ����ýڵ���α�
    space[mov].cur = 0; //��ʾ����ڵ�Ϊ���ýڵ�����һ���ڵ�
    return 1;
}

void Traverse_SL(SLinkList space){
    //���������̬����
    int i = space[MAXSIZE - 1].cur;
    while (i)
    {
        printf("data[%d]=%d\t",i,space[i].data);
        i = space[i].cur;
    }
}

int Insert_SL(SLinkList space,int index,int e){
    int i = Malloc_SL(space);
    int mov = space[MAXSIZE - 1].cur; //�ҵ���һ���ڵ���½Ǳ�
    for( int j=1; j<index-1; j++){    //�����ҵ�Ҫ����ڵ�λ��
        mov = space[mov].cur;
    }
    space[i].cur = space[mov].cur;
    space[i].data = e;
    space[mov].cur = i;
    return 1;

}
//ɾ��λ�ýڵ㣬����������ظ�e
int Delete_SL(SLinkList space,int index, int *e){
    int mov = space[MAXSIZE - 1].cur;
    for(int j=1;j<index-1;j++){ //���α��ƶ���indexǰһ���ڵ�
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




