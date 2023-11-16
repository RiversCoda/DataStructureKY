#include <bits/stdc++.h>
using namespace std;

struct binTreeNode {
    char data;
    binTreeNode *left;
    binTreeNode *right;
    binTreeNode(char d, binTreeNode *l = nullptr, binTreeNode *r = nullptr) : data(d), left(l), right(r) {}
};

// 创建二叉树
binTreeNode *createBinTree()
{
    char ch;
    cin >> ch;
    if (ch == '#')
        return nullptr;
    binTreeNode *root = new binTreeNode(ch);
    root->left = createBinTree();
    root->right = createBinTree();
    return root;
}

// 根据输入的前缀表达式和中缀表达式创建二叉树
binTreeNode *createBinTreeFromPreAndIn(string pre, string in)
{
    if (pre.empty())
        return nullptr;
    char ch = pre[0];
    int pos = in.find(ch);
    binTreeNode *root = new binTreeNode(ch);
    root->left = createBinTreeFromPreAndIn(pre.substr(1, pos), in.substr(0, pos));
    root->right = createBinTreeFromPreAndIn(pre.substr(pos + 1), in.substr(pos + 1));
    return root;
}

// 根据输入的后缀表达式和中缀表达式创建二叉树并输出二叉树形状
void createBinTreeFromPostAndInAndPrint(){
    // 输入前缀表达式和中缀表达式
    string pre, in;
    cin >> pre >> in;
    // 根据前缀表达式和中缀表达式创建二叉树
    binTreeNode *root = createBinTreeFromPreAndIn(pre, in);
    // 输出二叉树形状，用z表示空节点，每层单独一行
    queue<binTreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        bool flag = false;
        for (int i = 0; i < size; i++) {
            binTreeNode *node = q.front();
            q.pop();
            if (node == nullptr) {
                cout << "z ";
                q.push(nullptr);
                q.push(nullptr);
            }
            else {
                cout << node->data << " ";
                q.push(node->left);
                q.push(node->right);
                if (node->left != nullptr || node->right != nullptr)
                    flag = true;
            }
        }
        cout << endl;
        if (!flag)
            break;
    }
}
int main()
{
    createBinTreeFromPostAndInAndPrint();
}