#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int n, res = 0x80000000, a[N][N], f[N];

int main() {
    memset(f, 0x80, sizeof(f));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) scanf("%d", &a[i][j]);
    }
    f[1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = i; j; j--) {
            f[j] = max(f[j], f[j - 1]) + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) res = max(res, f[i]);
    printf("%d", res);
    return 0;
}
