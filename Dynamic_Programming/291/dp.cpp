#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 12, M = 1 << N;
int n, m, cnt;
ll dp[N][M];
bool st[M];

int main() {
    scanf("%d%d", &n, &m);
    while (n || m) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 1 << n; i++) {
            st[i] = true;
            cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    if (cnt % 2) {
                        st[i] = false;
                        break;
                    }
                    cnt = 0;
                } else cnt++;
            }
            if (cnt % 2) st[i] = false;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < 1 << n; j++) {
                for (int k = 0; k < 1 << n; k++) {
                    if (!(j & k) && st[j | k]) dp[i][j] += dp[i - 1][k];
                }
            }
        }
        printf("%lld\n", dp[m][0]);
        scanf("%d%d", &n, &m);
    }
    return 0;
}