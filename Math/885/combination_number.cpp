#include <iostream>
using namespace std;

const int N = 2010, MOD = 1e9 + 7;
int n, a, b, c[N][N];

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }
    return 0;
}