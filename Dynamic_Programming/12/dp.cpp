#include <iostream>
using namespace std;

const int N = 1010;
int n, m, v[N], w[N], dp[N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", v + i, w + i);
    for (int i = n; i; i--) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (m >= v[i] && dp[i][m] == dp[i + 1][m - v[i]] + w[i]) {
            printf("%d ", i);
            m -= v[i];
        }
    }
    return 0;
}