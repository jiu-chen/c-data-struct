#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"

#define TRUE 1
#define FALSE 0

Status InitList_Sq(SqList *L)
{
    L->length = 0;
    (*L).elem = (LElemType_Sq *)malloc(LIST_INIT_SIZE * sizeof(LElemType_Sq));
    if (!(*L).elem)
        exit(OVERFLOW);
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return OK;
}

// 清空顺序表
void ClearList_Sq(SqList *L)
{
    L->length = 0;
}

// 销毁顺序表
void DestroyList_Sq(SqList *L)
{
    L->elem = NULL;
    L->listsize = 0;
    L->length = 0;
}

Status ListEmpty_Sq(SqList L)
{
    return L.length == 0 ? TRUE : FALSE;
}

int ListLength_Sq(SqList L)
{
    return L.length;
}

Status GetElem_Sq(SqList L, int i, LElemType_Sq *e)
{

    if (i < 1 || i >= L.length)
    {
        return ERROR;
    }
    *e = L.elem[i - 1];
    return OK;
}

int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq))
{
    int i = 1;
    while (i <= L.length && !Compare(e, L.elem[i - 1]))
    {
        /* code */
        ++i;
    }
    if (i <= L.length)
        return i;
    return 0;
}

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
{
    int i = 1;
    if (L.elem[0] != cur_e)
    {
        while (i < L.length && L.elem[i] != cur_e)
        {
            ++i;
        }
        if (i < L.length)
        {
            *pre_e = L.elem[i - 1];
            return OK;
        }
    }
    return ERROR;
}

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
{
    int i = 0;
    while (i < L.length && L.elem[i] != cur_e)
    {
        ++i;
    }
    if (i < L.length - 1) // L.length - 1表示数组的最后一个元素
    {
        *next_e = L.elem[i + 1];
        return OK;
    }
    return ERROR;
}

//插入操作
//i表示插入的位置，在第i个元素位置插入，从1开始计数
// 1 2 4 8
//在第三个元素位置插入3，变为1 2 3 4 8
// 在第5个元素位置插入22，变为1 2 4 8 22
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
    LElemType_Sq *newbase;
    LElemType_Sq *p, *q;
    if (i < 1 || i > L->length + 1) // i值不合法
    {
        return ERROR;
    }
    if (L->length > L->listsize)
    {
        newbase = (LElemType_Sq *)realloc(L->elem, (L->listsize = LISTINCREMENT) * sizeof(LElemType_Sq));
        if (!newbase)
            exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    q = &(*L).elem[i - 1];
    for (p = &(*L).elem[L->length - 1]; p > q; p--)
    {
        *(p + 1) = *p;
    }
    *q = e;
    L->length++;
    return OK;
}

Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
{
    if (L->length == 0)
    {
        return ERROR;
    }

    if (i < 1 || i > L->length)
    {
        return ERROR;
    }

    LElemType_Sq *p, *q;
    p = &(*L).elem[i - 1];
    *e = *p;
    q = &(*L).elem[L->length - 1];

    for (++p; p < q; ++p)
    {
        *(p - 1) = *p;
    }
    L->length--; //表长减1
    return TRUE;
}

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq))
{
    for (int i = 0; i < L.length; i++)
    {
        Visit(L.elem[i]);
    }
    return OK;
}
#endif