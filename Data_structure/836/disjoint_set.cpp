#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, a, b, pa, pb, p[N];
char op[2];

int find(int x);

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        scanf("%s%d%d", op, &a, &b);
        pa = find(a), pb = find(b);
        if (op[0] == 'M') {
            if (pa != pb) p[pa] = pb;
        } else {
            if (pa == pb) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
