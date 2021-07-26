#define MAXSIZE 50
typedef int ElemType;
typedef int STATUS;

// 线性表
// 数组从0开始，线性表从1开始
// 用数组实现线性表
typedef struct
{
    /* data */
    ElemType data[MAXSIZE];
    int lentgh;
} SqList;

// 所谓函数声明（Declaration），就是告诉编译器我要使用这个函数，你现在没有找到它的定义不要紧，请不要报错，稍后我会把定义补上
// 将线性表L中的第i个位置元素值返回给e
STATUS GetElem(SqList L, int i, ElemType *e);
// 在线性表L中第i个位置之前插入新元素e
STATUS ListInsert(SqList *L, int i, ElemType e);
// 删除线性表L中第i个元素，并用e返回其值
STATUS ListDelete(SqList *L, int i, ElemType e);