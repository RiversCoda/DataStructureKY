#include <bits/stdc++.h>
using namespace std;
#define N 200020
// 并查集unionFindSet
// 朴素并查集ufset
class UFSet {
public:
    // init
    UFSet(int n)
    {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }

    int find(int x)
    {
        if (x != p[x])
            p[x] = find(p[x]);
        return p[x];
    }

    void unionSet(int x, int y)
    {
        p[find(x)] = find(y);
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }

private:
    int p[N];
};

// 维护size的并查集ufset_size
class UFSetSize {
public:
    // init
    UFSetSize(int n)
    {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (x != p[x])
            p[x] = find(p[x]);
        return p[x];
    }

    void unionSet(int x, int y)
    {
        size[find(y)] += size[find(x)];
        p[find(x)] = find(y);
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }

    int getSize(int x)
    {
        return size[find(x)];
    }

private:
    int p[N];
    int size[N];
};

// 维护到根节点距离的并查集ufset_dist
class UFSetDist {
public:
    // init
    UFSetDist(int n)
    {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            dist[i] = 0;
        }
    }

    int find(int x)
    {
        if (x != p[x]) {
            int t = p[x];
            p[x] = find(p[x]);
            dist[x] += dist[t];
        }
        return p[x];
    }

    void unionSet(int x, int y)
    {
        p[find(x)] = find(y);

        // 根据具体问题，初始化find(x)的偏移量
        int distance = 1; // x到y的距离
        dist[find(x)] = distance;
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }

    int getDist(int x, int y)
    {
        if (isSame(x, y))
            return abs(dist[x] - dist[y]);
        else
            return -1;
    }

private:
    int p[N];
    int dist[N];
};
