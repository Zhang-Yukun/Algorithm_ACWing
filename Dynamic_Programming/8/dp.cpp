#include <iostream>
using namespace std;

const int N = 1010;
int n, p, q, v[N], m[N], w[N], dp[N][N];

int main() {
    scanf("%d%d%d", &n, &p, &q);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", v + i, m + i, w + i);
    for (int i = 1; i <= n; i++) {
        for (int j = p; j >= v[i]; j--) {
            for (int k = q; k >= m[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - v[i]][k - m[i]] + w[i]);
            }
        }
    }
    printf("%d", dp[p][q]);
    return 0;
}