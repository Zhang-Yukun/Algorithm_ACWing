#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n, m, a, b, idx, h[N], e[N], ne[N], d[N];

void add(int a, int b);
int bfs(int n);

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    printf("%d", bfs(n));
    return 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int n) {
    memset(d, -1, sizeof(d));
    d[1] = 0;
    queue<int> q;
    int node;
    q.push(1);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (int i = h[node]; i != -1; i = ne[i]) {
            if (d[e[i]] == -1) {
                q.push(e[i]);
                d[e[i]] = d[node] + 1;
            }
        }
    }
    return d[n];
}