#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n, m, a, b, idx, d[N], h[N], e[N], ne[N];

void add(int a, int b);
int bfs(int u);

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    printf("%d", bfs(1));
    return 0;
}

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs(int u) {
    memset(d, -1, sizeof(d));
    d[1] = 0;
    queue<int> q;
    int t = 0, j = 0;
    q.push(1);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            j = e[i];
            if (d[j] == -1) {
                q.push(j);
                d[j] = d[t] + 1;
            }
        }
    }
    return d[n];
}