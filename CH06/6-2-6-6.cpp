#include <bits/stdc++.h>
using namespace std;

#define MAXV 100 // 假设最大顶点数为100，根据实际需要调整

typedef struct {
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
} MGraph;

int IsExistEL(MGraph G){
    int cnt = 0; // cnt统计度为奇数的顶点个数
    for (int i = 0; i < G.numVertices; i++) {
        int num = 0; // num统计本行度的个数
        for (int j = 0; j < G.numVertices; j++) {
            num += G.Edge[i][j]; // 每存在一条连接顶点i的边，num就会+1
        }
        if (num % 2 == 1) { // 当度为奇数时，计数器+1
            cnt++;
        }
    }
    return cnt == 0 || cnt == 2; // 只有度为奇数的点的个数为0或2时返回1.
}

int main() {
    // 使用freopen重定向输入输出
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    MGraph G;
    // 读入图的顶点数和边数
    cin >> G.numVertices >> G.numEdges;

    // 读入顶点信息
    for (int i = 0; i < G.numVertices; i++) {
        cin >> G.VerticesList[i];
    }

    // 初始化邻接矩阵
    for (int i = 0; i < G.numVertices; i++) {
        for (int j = 0; j < G.numVertices; j++) {
            G.Edge[i][j] = 0;
        }
    }

    // 读入边信息并填充邻接矩阵
    for (int i = 0; i < G.numEdges; i++) {
        int u, v;
        cin >> u >> v;
        G.Edge[u][v] = G.Edge[v][u] = 1; // 假设边是无向的
    }

    // 调用算法函数并输出结果
    cout << (IsExistEL(G) ? "Euler Path Exists" : "No Euler Path") << endl;

    // 关闭文件流
    fclose(stdin);
    fclose(stdout);

    return 0;
}
