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