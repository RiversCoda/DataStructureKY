#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct LNode {
    int num;
    struct LNode *next;
} LNode, *LinkList;
// 题目要求：重排链表使其符合a1 an a2 an-1 a3 an-2 a4 an-3...


// 题目思路：
// 设置2指针p和mid，p每次走2步，mid每次走1步得到链表中间位置
// 将后半链表就地逆置
// 分别从头部和后半开始，将后半插入前半

// 综上时间复杂度为On、空间复杂度均为O1

// 输出链表内容
void printList(LinkList L)
{
    LNode *p = L->next;
    while (p) {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
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

void reverseList(LNode* &head) {
    if (!head || !head->next) return;  // If list has 0 or 1 node, just return

    LNode *prev = NULL, *current = head, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void change_by_ques_order(LNode * L) {
    if (!L || !L->next || !L->next->next) return; // 0, 1 or 2 elements

    LNode *p = L, *mid = L;
    while (p->next && p->next->next) {
        p = p->next->next;
        mid = mid->next;
    }

    LNode* secondHalf = mid->next;
    mid->next = NULL; // split the list into two
    reverseList(secondHalf); // reverse the second half

    // Now, weave the two lists together
    LNode *firstHalf = L->next;
    while (firstHalf && secondHalf) {
        LNode* temp1 = firstHalf->next;
        LNode* temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        if (temp1) {
            secondHalf->next = temp1;
        }

        firstHalf = temp1;
        secondHalf = temp2;
    }
}

int main()
{
    freopen("2-3-24.in", "r", stdin);
    LinkList L = NULL;

    // 初始化头结点
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    list_tail_insert(L);

    printList(L);

    // process
    change_by_ques_order(L);
    // output

    printList(L);

    return 0;
}
