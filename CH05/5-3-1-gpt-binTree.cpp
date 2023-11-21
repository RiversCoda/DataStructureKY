#include <bits/stdc++.h>
using namespace std;

struct binTreeNode {
    char data;
    binTreeNode *left;
    binTreeNode *right;
    // tag: 线索flag tag
    // tag = 0说明指向孩子，tag = 1说明指向线索
    bool ltag;
    bool rtag;
    binTreeNode(char d, binTreeNode *l = nullptr, binTreeNode *r = nullptr) : data(d), left(l), right(r) {}
};

binTreeNode *createBinTreeFromPreAndIn(const string &pre, const string &in, int preStart, int preEnd, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;

    char ch = pre[preStart];
    int pos = in.find(ch, inStart);
    binTreeNode *root = new binTreeNode(ch);

    root->left = createBinTreeFromPreAndIn(pre, in, preStart + 1, preStart + pos - inStart, inStart, pos - 1);
    root->right = createBinTreeFromPreAndIn(pre, in, preStart + pos - inStart + 1, preEnd, pos + 1, inEnd);

    return root;
}

void printBinTree(binTreeNode *root)
{
    if (!root)
        return;

    queue<binTreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            binTreeNode *node = q.front();
            q.pop();

            if (node) {
                cout << node->data << " ";
                q.push(node->left);
                q.push(node->right);
            }
            else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}

// 前中后序遍历本质上遍历的顺序是一样的，只是访问节点的时机不同
// 三种遍历的递归实现

// 使用.来访问一个对象的成员。
// 使用->来访问一个指针指向的对象的成员。

void preOrder(binTreeNode *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(binTreeNode *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// 中序线索化二叉树
void inThread(binTreeNode *root, binTreeNode *&pre)
{
    if (!root)
        return;
    inThread(root->left, pre); // 递归左子树

    // 访问时执行线索化
    if (!root->left) { // 如果当前节点没有左孩子，将ltag置为1，left指向前驱节点
        root->ltag = 1;
        root->left = pre;
    }
    if (pre && !pre->right) {
        pre->rtag = 1;
        pre->right = root;
    }

    // 更新pre
    pre = root;
    inThread(root->right, pre); // 递归右子树
}
// 求中序线索化二叉树的第一个节点
binTreeNode *firstInOrderNode(binTreeNode *root)
{
    // 一直向左走直到找到第一个ltag为1的节点(第一个没有左孩子的节点),即中序遍历的第一个节点
    while (root->ltag == 0)
        root = root->left;
    return root;
}
// 求中序线索化二叉树的后继节点
binTreeNode *nextInOrderNode(binTreeNode *root)
{
    // 如果rtag为1，直接返回right
    if (root->rtag == 1)
        return root->right;
    // 如果rtag为0，返回右子树的第一个节点
    return firstInOrderNode(root->right);
}
// 中序线索化二叉树的中序遍历
void inThreadOrder(binTreeNode *root)
{
    // 找到第一个节点
    root = firstInOrderNode(root);
    while (root) {
        cout << root->data << " ";
        root = nextInOrderNode(root);
    }
}

void postOrder(binTreeNode *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// 三种遍历的非递归实现
void stackInOrder(binTreeNode *root)
{
    stack<binTreeNode *> s;
    binTreeNode *p = root;
    // L-N-R
    while (p || !s.empty()) { // 当前树空且栈空时才停止循环

        // 等价于LNR中递归遍历L左子树,将路上的节点放入栈中
        while (p) {
            s.push(p);
            p = p->left;
        }

        // 访问节点
        p = s.top();
        s.pop();
        cout << p->data << " ";

        // 访问右子树
        p = p->right;
    }
}

void stackPreOrder(binTreeNode *root)
{
    stack<binTreeNode *> s;
    binTreeNode *p = root;
    // N-L-R
    while (p || !s.empty()) {
        if (p) {
            // 先访问当前节点
            cout << p->data << " ";

            // 访问后入栈处理
            s.push(p);

            // 访问完之后左递归
            p = p->left;
        }
        else {
            // 向左递归完后重新指向栈顶（栈顶即为上一层）
            p = s.top();
            s.pop(); // 栈顶出栈，并走向其右子树
            p = p->right;
        }
    }
}

void stackPreOrder2(binTreeNode *root)
{
    stack<binTreeNode *> s;
    binTreeNode *p = root;
    // N-L-R
    // 先把根节点放进来
    s.push(root);

    while (!s.empty()) {
        // 访问栈顶
        p = s.top();
        s.pop();
        cout << p->data << " ";

        // 右节点先入栈，因为先入栈的后访问
        if (p->right)
            s.push(p->right);
        if (p->left)
            s.push(p->left);
    }
}

void stackPostOrder(binTreeNode *root)
{
    stack<binTreeNode *> s;
    binTreeNode *p = root, *lastVisited = nullptr;
    // L-R-N
    while (p || !s.empty()) {
        // 左子树循环入栈
        while (p) {
            s.push(p);
            p = p->left;
        }
        // 指向上一层的右子树，准备访问
        p = s.top();
        // 右节点存在且未被放翁，转向右节点
        if (p->right && p->right != lastVisited) {
            p = p->right;
        }
        // 如果右子树不存在或者以及被访问过
        else {
            // N:访问当前节点，出栈，
            cout << p->data << " ";
            s.pop();
            lastVisited = p; // 记录上一次访问的节点
            p = nullptr;     // 使得下一次循环不会再次访问当前节点的左子树
        }
    }
}

// 层次遍历
void levelOrder(binTreeNode *root)
{
    queue<binTreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        // 顺序：出队->访问->左子树入队->右子树入队
        binTreeNode *node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

void deleteTree(binTreeNode *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    freopen("input1.txt", "r", stdin);
    string pre, in;
    cin >> pre >> in;
    binTreeNode *root = createBinTreeFromPreAndIn(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    // printBinTree(root);
    // stackInOrder(root);
    // stackPostOrder(root);
    // stackPreOrder2(root);
    // stackPreOrder(root);
    // inThread(root, root);
    deleteTree(root);
}
