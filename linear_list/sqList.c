#include "sqList.h"
#include <stdio.h>

#define TRUE 1
#define FALSE 0

void InitList(SqList *L)
{
    L->lentgh = 0;
}

int Length(SqList *L)
{
    return L->lentgh;
}

// create
int CreateList(SqList *L, int a[], int len)
{
    if (len > MAXSIZE)
    {
        printf("空间不足，无法创建线性表\n");
        return FALSE;
    }
    for (int i = 0; i < len; i++)
    {
        L->data[i] = a[i];
    }
    L->lentgh = len;
    return TRUE;
}

// GetElem: 取第i个元素
int GetElem(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i >= L->lentgh)
    {
        return FALSE;
    }
    *e = L->data[i - 1];
    return TRUE;
}

void Display(SqList *L)
{
    for (int i = 0; i < L->lentgh; i++)
    {
        printf("%d\t", L->data[i]);
    }
    printf("\n");
}

//插入操作
//i表示插入的位置，在第i个元素之前插入，从1开始计数
// 1 2 4 5
//在第三个元素之前插入3，变为1 2 3 4 5
int ListInsert(SqList *L, int i, ElemType e)
{
    if (L->lentgh == MAXSIZE) //线性表满了
    {
        return FALSE;
    }
    if (i < 1 || i > L->lentgh) // i不在范围内
    {
        return TRUE;
    }
    for (int k = L->lentgh - 1; k >= i - 1; k--) // i是元素位置，不是下标
    {
        /* code */
        L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;
    L->lentgh++;

    return TRUE;
}

int ListDelete(SqList *L, int i, ElemType *e)
{
    if (L->lentgh == 0)
    {
        return FALSE;
    }

    int k;
    if (i < 1 || i > L->lentgh)
    {
        return TRUE;
    }

    *e = L->data[i - 1];
    for (int k = i; k < L->lentgh; k++)
    {
        /* code */
        L->data[k - 1] = L->data[k];
    }
    L->lentgh--;
    return TRUE;
}

void ClearList(SqList *L)
{
    L->lentgh = 0;
}

int IsEmpty(SqList *L)
{
    return L->lentgh == 0;
}

int Locate(SqList *L, int v, int *index)
{
    if (L->lentgh <= 0)
    {
        return FALSE;
    }
    for (int i = 0; i < L->lentgh; i++)
    {
        if (L->data[i] == v)
        {
            *index = i + 1;
            return TRUE;
        }
    }
    return FALSE;
}