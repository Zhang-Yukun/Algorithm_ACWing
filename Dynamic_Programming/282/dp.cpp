#include <iostream>
using namespace std;

const int N = 310;
int n, l, r, s[N], dp[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]), s[i] += s[i - 1];
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            l = i, r = i + len - 1;
            dp[l][r] = 0x3f3f3f3f;
            for (int k = i; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    printf("%d", dp[1][n]);
    return 0;
}