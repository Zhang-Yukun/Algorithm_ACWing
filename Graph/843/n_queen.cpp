#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
int n;
bool row[N], col[N], diag[2 * N], udiag[N];
char g[N][N];

void dfs(int x, int y, int k);

int main() {
    memset(g, '.', sizeof(g));
    scanf("%d", &n);
    dfs(0, 0, 0);
    return 0;
}

void dfs(int x, int y, int k) {
    if (y == n) y = 0, x++;
    if (x == n) {
        if (k == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%c", g[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        return;
    }
    dfs(x, y + 1, k);
    if (!row[x] && !col[y] && !diag[x + y] && !udiag[n - x + y - 1]) {
        g[x][y] = 'Q';
        row[x] = col[y] = diag[x + y] = udiag[n - x + y - 1] = true;
        dfs(x, y + 1, k + 1);
        g[x][y] = '.';
        row[x] = col[y] = diag[x + y] = udiag[n - x + y - 1] = false;
    }
}
