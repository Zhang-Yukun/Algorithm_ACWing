#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, a, b, pa, pb, p[N], cnt[N];
char op[3];

int find(int x);

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            pa = find(a), pb = find(b);
            if (pa != pb) {
                p[pa] = pb;
                cnt[pb] += cnt[pa];
            }
        } else if (op[1] == '1') {
            scanf("%d%d", &a, &b);
            pa = find(a), pb = find(b);
            if (pa == pb) printf("Yes\n");
            else printf("No\n");
        } else {
            scanf("%d", &a);
            pa = find(a);
            printf("%d\n", cnt[pa]);
        }
    }
    return 0;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}