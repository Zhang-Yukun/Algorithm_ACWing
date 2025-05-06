#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, l, r, c, t, d[N];

void add(int l, int r, int c);

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        add(i, i, t);
    }
    while (m--) {
        scanf("%d%d%d", &l, &r, &c);
        add(l, r, c);
    }
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        printf("%d ", d[i]);
    }
    return 0;
}