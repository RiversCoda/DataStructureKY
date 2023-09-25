#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct LNode {
    int num;
    struct LNode *next;
} LNode, *LinkList;

// *LinkList是头指针，也可以代指整个链表

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
        // 实际上是将头节点后的内容接到s后面，然后把头节点指向s
    }
    return L;
}

LinkList list_tail_insert(LinkList &L)
{
    LNode *s, *end;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    end = L;

    while (cin >> x) {
        s = (LNode *)malloc(sizeof(LNode));
        s->num = x;
        end->next = s;
        end = s;
        // 实际上是将s插入end位置后，将end指向新节点同样的位置
    }
    end->next = NULL;
    return L;
}


LNode *findByOrder(LinkList &L, int x)
{
    if (x < 1)
        return NULL;
    int j = 1;
    LNode *p = L->next;
    while (p != NULL && j < x) {
        p = p->next;
        j++;
        // 实际上是让p首先指向头节点的下一个，然后依次向后查找
    }
    return p;
}

LNode *findByValue(LinkList &L, int v){
    LNode *p = L->next;
    while(p!=NULL && p->num != v){
        p = p->next;
    }
    return p;
}

bool insert_after(LinkList &L, int n, int x){
    LNode *s, *p = L->next;
    s = (LNode *)malloc(sizeof(LNode));
    int count = 1;
    while(p != NULL && count < n){
        p = p->next;
        count++;
    }

    if(p == NULL) { // 如果n大于链表的长度
        free(s); // 释放之前分配的内存
        return false;
    }

    s->next = p->next;
    s->num = x;
    p->next = s;
    return true;
}

bool delete_by_order(LinkList &L, int n) {
    LNode *p = L; // 注意，这里从头结点开始
    int count = 1;

    // 找到第n-1个节点
    while (p != NULL && count < n) {
        p = p->next;
        count++;
    }

    // 如果p是NULL或者p的下一个节点是NULL（即第n个节点不存在）
    if (p == NULL || p->next == NULL) {
        return false;
    }

    // 删除第n个节点
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    
    return true;
}


// 你之前给出的代码部分，这里省略...

// 输出链表内容
void printList(LinkList L) {
    LNode* p = L->next;
    while (p) {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    LinkList L = NULL;

    // 初始化头结点
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    // 使用insert_after函数创建链表 12345
    for (int i = 1; i <= 5; i++) {
        insert_after(L, i-1, i);  // 在第i-1个节点后插入数值i
    }

    cout << "Created linked list: ";
    printList(L);

    return 0;
}
