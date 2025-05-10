#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e2 + 10, M = 1e5 + 10;
int n, m, k, x, y, z, res, d[N], b[N];
struct Edge {
    int a, b, c;
} e[M];

int bellman_ford(int k);

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        e[i] = {x, y, z};
    }
    res = bellman_ford(k);
    if (res > 0x3f3f3f3f / 2) printf("impossible");
    else printf("%d", res);
    return 0;
}

int bellman_ford(int k) {
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(b, d, sizeof(d));
        for (int j = 0; j < m; j++) {
            d[e[j].b] = min(d[e[j].b], b[e[j].a] + e[j].c);
        }
    }
    return d[n];
}