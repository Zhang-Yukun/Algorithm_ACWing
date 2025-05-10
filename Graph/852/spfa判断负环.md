# spfa判断负环

给定一个 $n$ 个点 $m$ 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你判断图中是否存在负权回路。

## 输入格式

第一行包含整数 $n$ 和 $m$。

接下来 $m$ 行每行包含三个整数 $x,y,z$，表示存在一条从点 $x$ 到点 $y$ 的有向边，边长为 $z$。

## 输出格式

如果图中存在负权回路，则输出 `Yes`，否则输出 `No`。

数据范围

$$
1 \le n \le 2000, \\
1 \le m \le 10000, \\
图中涉及边长绝对值均不超过 10000。
$$

## 输入样例：

```text
3 3
1 2 -1
2 3 4
3 1 -4
```

## 输出样例：

```text
Yes
```

## Solution

```Cpp
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n, m, x, y, z, idx, h[N], e[N], w[N], ne[N], d[N], cnt[N];
bool v[N];

void add(int a, int b, int c);
bool spfa();

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    if (spfa()) printf("Yes");
    else printf("No");
    return 0;
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    int node;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        v[i] = true;
    }
    while (!q.empty()) {
        node = q.front();
        q.pop();
        v[node] = false;
        for (int i = h[node]; i != -1; i = ne[i]) {
            if (d[e[i]] > d[node] + w[i]) {
                d[e[i]] = d[node] + w[i];
                cnt[e[i]] = cnt[node] + 1;
                if (cnt[e[i]] == n) return true;
                if (!v[e[i]]) {
                    q.push(e[i]);
                    v[e[i]] = true;
                }
            }
        }
    }
    return false;
}
```
