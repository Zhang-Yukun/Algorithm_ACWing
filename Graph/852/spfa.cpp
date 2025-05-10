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