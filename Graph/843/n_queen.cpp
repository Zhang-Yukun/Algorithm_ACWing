#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;
int n;
bool col[N], diag[2 * N], udiag[2 * N];
char g[N][N];

void dfs(int r);

int main() {
    memset(g, '.', sizeof(g));
    scanf("%d", &n);
    dfs(0);
    return 0;
}

void dfs(int r) {
    if (r == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%c", g[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !diag[r + c] && !udiag[n - r + c - 1]) {
            g[r][c] = 'Q';
            col[c] = diag[r + c] = udiag[n - r + c - 1] = true;
            dfs(r + 1);
            col[c] = diag[r + c] = udiag[n - r + c - 1] = false;
            g[r][c] = '.';
        }
    }
}