
#include "link.h"

// # -> 1 -> 2 -> 3 -> NULL
int GetElem(LinkList *L, int i, ElemType *elem)
{
    LinkList *p;
    p = L->Next;
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