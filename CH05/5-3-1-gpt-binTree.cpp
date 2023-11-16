#include <bits/stdc++.h>
using namespace std;

struct binTreeNode {
    char data;
    binTreeNode *left;
    binTreeNode *right;
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

void postOrder(binTreeNode *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// 三种遍历的非递归实现
void stackPreOrder(binTreeNode *root)
{
    stack<binTreeNode *> s;
    binTreeNode *p = root;
    while (p || !s.empty()) {
        if (p) {
            cout << p->data << " ";
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}
void stackInOrder(binTreeNode *root)
{
    stack<binTreeNode *> s;
    binTreeNode *p = root;
    while(p || !s.empty()) {
        if(p) {
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top(); s.pop();
            cout << p->data << " ";
            p = p->left;
        }
    }
}
void stackPostOrder(binTreeNode *root)
{
    stack<binTreeNode *> s;
    binTreeNode *p = root, *lastVisited = nullptr;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top();
            if (p->right && p->right != lastVisited) {
                p = p->right;
            }
            else {
                cout << p->data << " ";
                s.pop();
                lastVisited = p;
                p = nullptr;
            }
        }
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
    printBinTree(root);
    deleteTree(root);
}
