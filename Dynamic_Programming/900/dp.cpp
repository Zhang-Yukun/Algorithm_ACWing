#include <iostream>
using namespace std;

const int N = 1010, MOD = 1e9 + 7;
int n, res, dp[N][N];

int main() {
    scanf("%d", &n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++) res = (res + dp[n][i]) % MOD;
    printf("%d", res);
    return 0;
}