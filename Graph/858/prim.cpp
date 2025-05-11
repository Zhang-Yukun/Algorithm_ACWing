#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e2 + 10;
int n, m, x, y, z, res, g[N][N], d[N];
bool v[N];

int prim();

int main() {
    memset(g, 0x3f, sizeof(g));
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = g[y][x] = min(g[x][y], z);
    }
    res = prim();
    if (res > 0x3f3f3f3f / 2) printf("impossible");
    else printf("%d", res);
    return 0;
}

int prim() {
    memset(d, 0x3f, sizeof(d));
    int t = 0, res = 0;
    for (int i = 0; i < n; i++) {
        t = 0;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && (!t || d[j] < d[t])) t = j;
        }
        v[t] = true;
        if (i && d[t] == 0x3f3f3f3f) return d[t];
        if (i) res += d[t];
        for (int j = 1; j <= n; j++) d[j] = min(d[j], g[t][j]);
    }
    return res;
}