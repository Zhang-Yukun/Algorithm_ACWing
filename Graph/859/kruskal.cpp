#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, m, x, y, z, a, b, pa, pb, res, cnt, p[N];
struct Edge{
    int a, b, c;
    bool operator <(const Edge &edge) {
        return c < edge.c;
    }
} e[N];

int find(int x);

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        e[i] = {x, y, z};
    }
    sort(e, e + m);
    for (int i = 0; i < m; i++) {
        a = e[i].a, b = e[i].b;
        pa = find(a), pb = find(b);
        if (pa != pb) {
            p[pa] = pb;
            res += e[i].c;
            cnt++;
        }
    }
    if (cnt < n - 1) printf("impossible");
    else printf("%d", res);
    return 0;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}