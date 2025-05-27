#include <iostream>
using namespace std;

const int N = 1010, M = 2e4 + 10;
int n, m, h, t, v[N], w[N], s[N], dp[2][M], q[M];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", v + i, w + i, s + i);
    for (int i = 1; i <= n; i++) {
        for (int r = 0; r < v[i]; r++) {
            h = t = 0;
            for (int j = r; j <= m; j += v[i]) {
                while (h < t && j - s[i] * v[i] > q[h]) h++;
                while (h < t && dp[(i - 1) & 1][q[t - 1]] + (j - q[t - 1]) / v[i] * w[i] <= dp[(i - 1) & 1][j]) t--;
                q[t++] = j;
                dp[i & 1][j] = dp[(i - 1) & 1][q[h]] + (j - q[h]) / v[i] * w[i];
            }
        }
    }
    printf("%d", dp[n & 1][m]);
    return 0;
}