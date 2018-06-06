#include <stdio.h>
#include <stdlib.h>

/*
    魔术师发牌问题
问题描述：
魔术师手中有A、2、3……J、Q、K十三张黑桃扑克牌。
在表演魔术前，魔术师已经将他们按照一定的顺序叠放好（有花色的一面朝下）。
魔术表演过程为：一开始，魔术师数1，然后把最上面的那张牌翻过来，是黑桃A；然后将其放到桌面上；
第二次,魔术师数1、2；将第一张牌放到这些牌的最下面，将第二张牌翻转过来，正好是黑桃2；
第三次，魔术师数1、2、3；将第1、2张牌依次放到这些牌的最下面，将第三张牌翻过来正好是黑桃3；
……直到将所有的牌都翻出来为止。问原来牌的顺序是如何的。
答案：1 8 2 5 10 3 12 11 9 4 7 6 13

*/
typedef struct Magic{
    int data;
    struct Magic *next;
}Magic,*MLinked;

//初始化一个13个节点长度的单向循环链表
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
