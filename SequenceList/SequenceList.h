#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include "../common/status.h"
#include <stdlib.h>
#include <stdio.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int LElemType_Sq;

// 线性表
// 数组从0开始，线性表从1开始

// 优点：
// - 无须为表示表中元素之间的逻辑关系而增加额外的存储空间
// - 可以快速存取表中位置的元素

// 确定
// -插入和删除需要移动大量元素
// - 容易造成存储空间的“碎片”

typedef struct
{
    LElemType_Sq *elem; //存储空间基址（指向第一个结点的指针）
    int length;         //当前顺序表长度
    int listsize;       //当前分配的存储容量
} SqList;

// 所谓函数声明（Declaration），就是告诉编译器我要使用这个函数，你现在没有找到它的定义不要紧，请不要报错，稍后我会把定义补上

/* 顺序表函数列表 */

// 初始化顺序表
Status InitList_Sq(SqList *L);

// 清空顺序表
void ClearList_Sq(SqList *L);

// 销毁顺序表
void DestroyList_Sq(SqList *L);

// 判断顺序表是否为空
Status ListEmpty_Sq(SqList L);

// 返回顺序表长度
int ListLength_Sq(SqList L);

// 用e接收顺序表L中第i个元素
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);

// 返回顺序表L中首个与e满足Compare关系的元素位序
int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));

// 用pre_e接收cur_e的前驱
Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);

// next_e接收cur_e的后继
Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);

// 在顺序表L的第i个位置上插入e
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);

// 删除顺序表L上第i个位置的元素，并用e返回
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);

// 用visit函数访问顺序表L
Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq));

#endif