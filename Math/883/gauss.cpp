#include <iostream>
#include <cmath>
using namespace std;

const int N = 110;
const double EPSILON = 1e-6;
int n, flag;
double a[N][N];

int gauss(double a[][N], int n);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) scanf("%lf", &a[i][j]);
    }
    flag = gauss(a, n);
    if (!flag) {
        for (int i = 0; i < n; i++) printf("%.2f\n", a[i][n]);
    } else if (flag == 1) {
        printf("Infinite group solutions");
    } else {
        printf("No solution");
    }
    return 0;
}

int gauss(double a[][N], int n) {
    int r, c, t;
    for (c = 0, r = 0; c < n; c++) {
        t = r;
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
        }
        if (fabs(a[t][c]) < EPSILON) continue;
        if (t != r) {
            for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        }
        for (int i = n; i > c - 1; i--) a[r][i] /= a[r][c];
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > EPSILON) {
                for (int j = n; j > c - 1; j--) a[i][j] -= a[i][c] * a[r][j];
            }
        }
        r++;
    }
    if (r < n) {
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > EPSILON) return 2;
        }
        return 1;
    }
    for (int i = n - 1; i > -1; i--) {
        for (int j = i + 1; j < n; j++) a[i][n] -= a[i][j] * a[j][n];
    }
    return 0;
}