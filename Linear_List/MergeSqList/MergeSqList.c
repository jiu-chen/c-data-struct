#include "MergeSqList.h"

/* 顺序表归并函数列表 */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc)
{
    int La_len, Lb_len;
    int i, j, k;

    La_len = ListLength_Sq(La);
    Lb_len = ListLength_Sq(Lb);

    k = 0;
    i = j = 1;
    LElemType_Sq ai, bj;

    InitList_Sq(Lc);

    while (i <= La_len && j <= Lb_len) //La及Lb均未扫描完
    {
        GetElem_Sq(La, i, &ai);
        GetElem_Sq(Lb, j, &bj);

        if (ai <= bj)
        {
            ListInsert_Sq(Lc, ++k, ai);
            i++;
        }
        else
        {
            ListInsert_Sq(Lc, ++k, bj);
            j++;
        }
    }

    while (i <= La_len) //表La还未扫描完
    {
        GetElem_Sq(La, i++, &ai);
        ListInsert_Sq(Lc, ++k, ai);
    }

    while (j <= Lb_len) //表Lb还未扫描完
    {
        GetElem_Sq(Lb, j++, &bj);
        ListInsert_Sq(Lc, ++k, bj);
    }
}

void MergeSqList_2(SqList La, SqList Lb, SqList *Lc);