#include <iostream>
using namespace std;

const int N = 110;
int n, flag, a[N][N];

int gauss(int a[][N], int n);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) scanf("%d", &a[i][j]);
    }
    flag = gauss(a, n);
    if (!flag) {
        for (int i = 0; i < n; i++) printf("%d\n", a[i][n]);
    } else if (flag == 1) printf("Multiple sets of solutions");
    else printf("No solution");
    return 0;
}

int gauss(int a[][N], int n) {
    int r, c, t;
    for (c = 0, r = 0; c < n; c++) {
        t = r;
        for (int i = r + 1; i < n; i++) {
            if (a[i][c]) {
                t = i;
                break;
            }
        }
        if (!a[t][c]) continue;
        if (t != r) {
            for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        }
        for (int i = r + 1; i < n; i++) {
            if (a[i][c]) {
                for (int j = n; j >= c; j--) a[i][j] ^= a[r][j];
            }
        }
        r++;
    }
    if (r < n) {
        for (int i = r; i < n; i++) {
            if (a[i][n]) return 2;
        }
        return 1;
    }
    for (int i = n - 1; i > -1; i--) {
        for (int j = i + 1; j < n; j++) {
            a[i][n] ^= a[i][j] & a[j][n];
        }
    }
    return 0;
}