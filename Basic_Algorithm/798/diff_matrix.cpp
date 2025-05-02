#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int n, m, q, t, x1, y1, x2, y2, c, d[N][N];

void add(int x1, int y1, int x2, int y2, int c);

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &t);
            add(i, j, i, j, t);
        }
    }
    while (q--) {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        add(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + d[i][j];
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void add(int x1, int y1, int x2, int y2, int c) {
    d[x1][y1] += c;
    d[x1][y2 + 1] -= c;
    d[x2 + 1][y1] -= c;
    d[x2 + 1][y2 + 1] += c;
}
