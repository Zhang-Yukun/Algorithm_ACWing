#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e2 + 10;
int n, m, x, y, z, g[N][N], d[N];
bool v[N];

int dijkstra(int n);

int main() {
    memset(g, 0x3f, sizeof(g));
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = min(g[x][y], z);
    }
    printf("%d", dijkstra(n));
    return 0;
}

int dijkstra(int n) {
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        t = 0;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && (!t || d[t] > d[j])) t = j;
        }
        v[t] = true;
        for (int j = 1; j <= n; j++) d[j] = min(d[j], d[t] + g[t][j]);
    }
    if (d[n] == 0x3f3f3f3f) return -1;
    else return d[n];
}