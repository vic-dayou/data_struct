#include <stdio.h>
#include <stdlib.h>

/*
    ħ��ʦ��������
����������
ħ��ʦ������A��2��3����J��Q��Kʮ���ź����˿��ơ�
�ڱ���ħ��ǰ��ħ��ʦ�Ѿ������ǰ���һ����˳����źã��л�ɫ��һ�泯�£���
ħ�����ݹ���Ϊ��һ��ʼ��ħ��ʦ��1��Ȼ���������������Ʒ��������Ǻ���A��Ȼ����ŵ������ϣ�
�ڶ���,ħ��ʦ��1��2������һ���Ʒŵ���Щ�Ƶ������棬���ڶ����Ʒ�ת�����������Ǻ���2��
�����Σ�ħ��ʦ��1��2��3������1��2�������ηŵ���Щ�Ƶ������棬���������Ʒ����������Ǻ���3��
����ֱ�������е��ƶ�������Ϊֹ����ԭ���Ƶ�˳������εġ�
�𰸣�1 8 2 5 10 3 12 11 9 4 7 6 13

*/
typedef struct Magic{
    int data;
    struct Magic *next;
}Magic,*MLinked;

//��ʼ��һ��13���ڵ㳤�ȵĵ���ѭ������
MLinked Init_ML(int n){
    MLinked head = (MLinked)malloc(sizeof(Magic));
    head->data = 0;
    head->next = NULL;
    MLinked p = head;
    while(n-- > 1){
        MLinked temp = (MLinked)malloc(sizeof(MLinked));
        temp->data = 0;
        temp->next = p->next;
        p->next = temp;
        p = temp;
    }
    p->next = head;
    return head;
}
void Traversal_ML(MLinked head){
    MLinked p = head;
    int i=1;
    while (1){
        printf("data[%d]->%d\t",i,p->data);
        p = p->next;
        if(p->next == head){
            printf("data[%d]->%d\t",i+1,p->data);
            break;
        }
        i++;
    }

}

int Licensing(MLinked head){
    int i = 1;
    MLinked p = head;
    while (i<=13)


}



int main()
{
    MLinked m = Init_ML(13);
    Traversal_ML(m);
    return 0;
}
