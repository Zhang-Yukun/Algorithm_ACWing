#include <iostream>
using namespace std;

const int N = 1010;
int n, m, tv, tw, v[N], w[N], s[N], dp[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", v + i, w + i, s + i);
    for (int i = 1; i <= n; i++) {
        if (s[i] == -1) {
            for (int j = m; j >= v[i]; j--) dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        } else if (s[i] == 0) {
            for (int j = v[i]; j <= m; j++) dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        } else {
            for (int k = 1; k <= s[i]; k *= 2) {
                tv = k * v[i];
                tw = k * w[i];
                s[i] -= k;
                for (int j = m; j >= tv; j--) dp[j] = max(dp[j], dp[j - tv] + tw);
            }
            if (s[i]) {
                tv = s[i] * v[i];
                tw = s[i] * w[i];
                for (int j = m; j >= tv; j--) dp[j] = max(dp[j], dp[j - tv] + tw);
            }
        }
    }
    printf("%d", dp[m]);
    return 0;
}