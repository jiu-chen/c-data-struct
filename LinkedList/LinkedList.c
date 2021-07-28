
#include "link.h"

// # -> 1 -> 2 -> 3 -> NULL
int GetElem(LinkList *L, int i, ElemType *elem)
{
    LinkList *p; //p指向头节点
    p = L->Next; //p指向首元节点
    int j = 1;
    while (p && j < i)
    {
        p = p->Next;
        j++;
    }
    if (!p)
    {
        return 0;
    }
    *elem = p->data;
    return 1;
}