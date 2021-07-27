typedef int ElemType;

typedef struct Node // 这个Node不能省略，因为指针域Next用到了类型
{
    /* data */
    ElemType data;
    struct Node *Next;
} Node;

typedef struct Node LinkList;

// -> 头节点 -> 节点1 -> ... -> NULL

// 空链表
// -> 表示头指针
// -> 头节点 -> NULL

// 查找链表中的第i个元素
int GetElem(LinkList *L, int i, ElemType *elem);
