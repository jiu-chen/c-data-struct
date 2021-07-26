#define MAXSIZE 10
typedef int ElemType;

// 线性表
// 数组从0开始，线性表从1开始

// 优点：
// - 无须为表示表中元素之间的逻辑关系而增加额外的存储空间
// - 可以快速存取表中位置的元素

// 确定
// -插入和删除需要移动大量元素
// - 容易造成存储空间的“碎片”

// 用数组实现线性表
typedef struct
{
    /* data */
    ElemType data[MAXSIZE];
    int lentgh;
} SqList;

// 所谓函数声明（Declaration），就是告诉编译器我要使用这个函数，你现在没有找到它的定义不要紧，请不要报错，稍后我会把定义补上

// 初始化线性表
void InitList(SqList *L);

// 创建线性表
int CreateList(SqList *L, int a[], int len);

int Length(SqList *L);

// 将线性表L中的第i个位置元素值返回给e
int GetElem(SqList *L, int i, ElemType *e);

// print elems
void Display(SqList *L);

// 在线性表L中第i个位置之前插入新元素e
int ListInsert(SqList *L, int i, ElemType e);
// 删除线性表L中第i个元素，并用e返回其值
int ListDelete(SqList *L, int i, ElemType *e);

int IsEmpty(SqList *L);
void ClearList(SqList *L);
int Locate(SqList *L, int v, int *index);