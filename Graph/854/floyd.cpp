#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e2 + 10;
int n, m, k, x, y, z, g[N][N];

void floyd();

int main() {
    memset(g, 0x3f, sizeof(g));
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = min(g[x][y], z);
    }
    floyd();
    while (k--) {
        scanf("%d%d", &x, &y);
        if (g[x][y] > 0x3f3f3f3f / 2) printf("impossible\n");
        else printf("%d\n", g[x][y]);
    }
    return 0;
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}