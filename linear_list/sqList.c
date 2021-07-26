#include <sqList.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

// getElem
STATUS GetElem(SqList L, int i, ElemType *e)
{
    if (i < 0 || i >= L.lentgh)
    {
        return ERROR;
    }
    *e = L.data[i];
    return OK;
}

//插入操作
//i表示插入的位置，在第i个元素之前插入，从1开始计数
// 1 2 4 5
//在第三个元素之前插入3，变为1 2 3 4 5
STATUS ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->lentgh == MAXSIZE) //线性表满了
    {
        return ERROR;
    }
    if (i < 1 || i > L->lentgh) // i不在范围内
    {
        return ERROR;
    }
    // if (i <= L->lentgh)
    // {
    for (int k = L->lentgh - 1; k >= i - 1; k--) // i是元素位置，不是下标
    {
        /* code */
        L->data[k + 1] = L->data[k];
    }
    // }
    L->data[k] = e;
    L->lentgh++;

    return OK;
}

STATUS ListDelete(SqList *L, int i, ElemType e)
{
    if (L->lentgh == 0)
    {
        return ERROR;
    }

    int k;
    if (i < 1 || i > L->lentgh)
    {
        return ERROR;
    }

    e = L->data[i - 1];
    for (int k = i; k < L->lentgh; k++)
    {
        /* code */
        L->data[k - 1] = L->data[k];
    }
    L->lentgh--;
    return OK;
}
