#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int res, n, m, a, b, h[N][N], dp[N][N], dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int dfs(int x, int y);

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) scanf("%d", &h[i][j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) res = max(res, dfs(i, j));
    }
    printf("%d", res);
    return 0;
}

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        a = x + dx[i];
        b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(a, b) + 1);
        }
    }
    return dp[x][y];
}