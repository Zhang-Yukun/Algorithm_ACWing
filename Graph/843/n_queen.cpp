#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
int n;
bool row[N], col[N], diag[2 * N], udiag[2 * N];
char g[N][N];

void dfs(int r, int c, int k);

int main() {
    memset(g, '.', sizeof(g));
    scanf("%d", &n);
    dfs(0, 0, 0);
    return 0;
}

void dfs(int r, int c, int k) {
    if (c == n) r++, c = 0;
    if (r == n) {
        if (k == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) printf("%c", g[i][j]);
            printf("\n");
            }
            printf("\n");
        }
        return;
    }
    dfs(r, c + 1, k);
    if (!row[r] && !col[c] && !diag[r + c] && !udiag[n - r + c - 1]) {
        g[r][c] = 'Q';
        row[r] = col[c] = diag[r + c] = udiag[n - r + c - 1] = true;
        dfs(r, c + 1, k + 1);
        row[r] = col[c] = diag[r + c] = udiag[n - r + c - 1] = false;
        g[r][c] = '.';
    }
}