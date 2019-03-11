/*线性表顺数存储，数组表示*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct LNode *List;
typedef int Position;
#define MaxSize 20
#define false -1
#define true 0
struct LNode{
    ElementType Data[MaxSize];
    int last;
};

//初始化实现,制造一个空的list
List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->last = -1;//元素从第一个开始，所以第一个序号是-1
    return L;
}
//像表中插入元素，尾插发
void push_back(List L,ElementType X)
{
    if (L->last == MaxSize - 1 ) {
        printf("线性表满了，无法插入元素\n");
        return ;
        /* code */
    }
    L->Data[++L->last] = X;
    printf("%d元素加入到线性表中\n",X);  
}
//打印线性表中的元素
void PrintList(List L)
{
    if (L->last == -1) {
        printf("线性表为空\n");
    }
    
    for(int i = 0; i <= L->last; i++)
    {
        printf("%d ",L->Data[i]);
    }
    printf("\n");
    
}

//插入操作，向表中插入元素
int Insert(List L,ElementType X,Position P)
{
    //判断是否表满
    if (L->last == MaxSize - 1) {
        /* code */
        printf("线性表已经满了，无法插入元素\n");
        return false;
    }
    //检查插入位置是否合法
    if (P < 0 || P > L->last) {
        /* code */
        printf("插入位置非法\n");
        return false;
    }
    for(int i = L->last; i >= P; i--)
    {
        L->Data[ i+1 ] = L->Data[ i ];
    }
    L->last++;
    L->Data[P] = X;
     printf("元素插入成功\n");
    return true;
}

/*删除操作
按照位置删除，传入位置，删除指定位置的元素
*/
int Delete(List L,Position P)
{
    //判断位置是否合法
    if (P < 0 || P > L->last) {
        printf("位置不合法，请检查输入\n");
        return false;
    }
    for(int  i = P; i <= L->last; i++)
    {
        L->Data[i-1] = L->Data[i];
    }
    L->last--;
    printf("%d位置的元素已经删除\n",P);
    return true;
}

int main()
{
    List L = MakeEmpty();
    PrintList(L);
    push_back(L,1);
    push_back(L,2);
    push_back(L,3);
    push_back(L,4);
    push_back(L,5);
    PrintList(L);
    printf("插入后：\n");
    Insert(L,99999,2);
    PrintList(L);
    printf("删除元素后：\n");
    Delete(L,4);
    PrintList(L);
    return 0;
}