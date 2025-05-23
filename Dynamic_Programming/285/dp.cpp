#include <iostream>
#include <cstring>
using namespace std;

const int N = 6010;
int n, x, y, root, idx, w[N], h[N], e[N], ne[N], dp[N][2];
bool v[N];

void add(int a, int b);
void dfs(int u);

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        add(y, x);
    }
    root = 1;
    while (v[root]) root++;
    dfs(root);
    printf("%d", max(dp[root][0], dp[root][1]));
    return 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++, v[b] = true;
}

void dfs(int u) {
    dp[u][1] = w[u];
    for (int i = h[u]; i != -1; i = ne[i]) {
        dfs(e[i]);
        dp[u][0] += max(dp[e[i]][0], dp[e[i]][1]);
        dp[u][1] += dp[e[i]][0];
    }
}