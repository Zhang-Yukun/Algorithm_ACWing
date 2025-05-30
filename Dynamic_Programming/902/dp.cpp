#include <iostream>
using namespace std;

const int N = 1010;
int n, m, f[N][N];
char a[N], b[N];

int main() {
    scanf("%d%s%d%s", &n, a + 1, &m, b + 1);
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int j = 1; j <= m; j++) f[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    printf("%d", f[n][m]);
    return 0;
}