#include <stdio.h>
#include "sqList.h"

// 编译
// * gcc -o sqlist main.c sqList.c

int main()
{
    SqList sqlist;
    InitList(&sqlist);

    int a[] = {6, 2, 9, 3, 5};
    int res = CreateList(&sqlist, a, 5);
    if (res == 0)
    {
        printf("create fail\n");
        return -1;
    }
    int elem;
    res = GetElem(&sqlist, 2, &elem);
    printf("第2个元素值为: %d\n", elem);
    printf("sqlist: ");
    Display(&sqlist);
    printf("length of sqlist: %d\n", Length(&sqlist));

    // 在第1个位置之前插入元素
    ListInsert(&sqlist, 1, 8);
    printf("after inserting: ");
    Display(&sqlist);
    ListDelete(&sqlist, 1, &elem);
    printf("after deleting: ");
    Display(&sqlist);

    int index;
    int value = 3;
    // int index, value = 3;
    // printf("index: %d\n", index);
    res = Locate(&sqlist, value, &index);
    if (res == 0)
    {
        printf("locate error\n");
    }
    else
    {
        printf("第%d个元素是%d\n", index, value);
    }
    ClearList(&sqlist);
    res = IsEmpty(&sqlist);
    printf("is empty: %d\n", res);

    return 0;
}