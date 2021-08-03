#include <stab.h>
#include "MergeSqList.h"

void PrintElem(LElemType_Sq e);

int main()
{
    SqList La, Lb, Lc1;
    LElemType_Sq a[4] = {3, 5, 8, 11};
    LElemType_Sq b[7] = {2, 6, 8, 9, 11, 15, 20};
    int i;
    InitList_Sq(&La);
    for (i = 1; i <= 4; i++)
    {
        ListInsert_Sq(&La, i, a[i - 1]);
    }
    InitList_Sq(&Lb);
    for (i = 1; i <= 7; i++)
    {
        ListInsert_Sq(&Lb, i, b[i - 1]);
    }

    printf("La = "); //输出La
    ListTraverse_Sq(La, PrintElem);
    printf("\n");
    printf("Lb = "); //输出Lb
    ListTraverse_Sq(Lb, PrintElem);
    printf("\n\n");

    MergeSqList_1(La, Lb, &Lc1);  //合并A与B,算法2.6
    printf("合并La和Lb为Lc1 = "); //输出Lc1
    ListTraverse_Sq(Lc1, PrintElem);
    printf("\n\n");
}

void PrintElem(LElemType_Sq e)
{
    printf("%d ", e);
}

/*
$ gcc -o main MergeSqList.c MergeSqList_main.c ../SequenceList/SequenceList.c 
$ ./merge                                                                      
La = 3 5 8 11 
Lb = 2 6 8 9 11 15 20 

合并La和Lb为Lc1 = 2 3 5 6 8 8 8 9 11 15 15 
*/