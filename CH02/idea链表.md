更多请见2-3-List

对于链表：
1. LinkList是一个指针，指向头部，也就是头指针，亦可以代表整个链表
2. 在创建数据空间时，为头指针分配空间，使用LinkList是因为其本身就是一个指针，不需要再加*
3. 在为数据节点分配空间时，使用LNode *s，因为s是一个指针，所以为其分配空间时需要加*

```cpp
typedef struct LNode {
    int num;
    struct LNode *next;
} LNode, *LinkList;

// 头插法建立单链表
LinkList list_head_insert(LinkList &L)
{
    LNode *s;
    int x;
    // init
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    // create
    while (cin >> x) {
        s = (LNode *)malloc(sizeof(LNode));
        s->num = x;
        s->next = L->next;
        L->next = s;
    }
    return L;
}
```
