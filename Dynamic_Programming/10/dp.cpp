#include <iostream>
using namespace std;

const int N = 110;
int n, m, p, root, idx = 1, v[N], w[N], dp[N][N], h[N], e[N], ne[N];

void add(int a, int b);
void dfs(int u);

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", v + i, w + i, &p);
        if (p == -1) root = i;
        else add(p, i);
    }
    dfs(root);
    printf("%d", dp[root][m]);
    return 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    for (int j = v[u]; j <= m; j++) dp[u][j] = w[u];
    for (int i = h[u]; i; i = ne[i]) {
        dfs(e[i]);
        for (int j = m; j >= v[u]; j--) {
            for (int k = 0; k <= j - v[u]; k++) {
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[e[i]][k]);
            }
        }
    }
}