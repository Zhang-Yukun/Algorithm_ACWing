#include <iostream>
using namespace std;

const int N = 1010, MOD = 1e9 + 7;
int n, m, v[N], w[N], dp[N], cnt[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", v + i, w + i);
    for (int i = 0; i <= m; i++) cnt[i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            if (dp[j - v[i]] + w[i] > dp[j]) {
                dp[j] = dp[j - v[i]] + w[i];
                cnt[j] = cnt[j - v[i]];
            } else if (dp[j - v[i]] + w[i] == dp[j]) {
                cnt[j] = (cnt[j] + cnt[j - v[i]]) % MOD;
            }
        }
    }
    printf("%d", cnt[m]);
    return 0;
}