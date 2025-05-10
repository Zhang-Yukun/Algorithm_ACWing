# spfa求最短路

给定一个 $n$ 个点 $m$ 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出 $1$ 号点到 $n$ 号点的最短距离，如果无法从 $1$ 号点走到 $n$ 号点，则输出 `impossible`。

数据保证不存在负权回路。

## 输入格式

第一行包含整数 $n$ 和 $m$。

接下来 $m$ 行每行包含三个整数 $x,y,z$，表示存在一条从点 $x$ 到点 $y$ 的有向边，边长为 $z$。

## 输出格式

输出一个整数，表示 $1$ 号点到 $n$ 号点的最短距离。

如果路径不存在，则输出 `impossible`。

## 数据范围

$$
1 \le n,m \le 10^5, \\
图中涉及边长绝对值均不超过 10000。
$$

## 输入样例：

```text
3 3
1 2 5
2 3 -3
1 3 4
```

输出样例：

```text
2
```

## Solution

```Cpp
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n, m, x, y, z, res, idx, h[N], e[N], w[N], ne[N], d[N];
bool v[N];

void add(int a, int b, int c);
int spfa();

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    res = spfa();
    if (res > 0x3f3f3f3f / 2) printf("impossible");
    else printf("%d", res);
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    queue<int> q;
    int node;
    q.push(1);
    v[1] = true;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        v[node] = false;
        for (int i = h[node]; i != -1; i = ne[i]) {
            if (d[e[i]] > d[node] + w[i]) {
                d[e[i]] = d[node] + w[i];
                if (!v[e[i]]) {
                    q.push(e[i]);
                    v[e[i]] = true;
                }
            }
        }
    }
    return d[n];
}
```
