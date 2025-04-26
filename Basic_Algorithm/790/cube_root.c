#include <stdio.h>

double n, res;

double cube_root(double left, double right);

int main() {
    scanf("%lf", &n);
    res = cube_root(-1e4, 1e4);
    printf("%.6f", res);
    return 0;
}

double cube_root(double left, double right) {
    double l = left, r = right, m = (l + r) / 2, t = 0;
    while (l <= r) {
        t = m * m * m;
        if ((t - n < 1e-9) && (t - n > -1e-9)) return m;
        else if (t > n) r = m;
        else l = m;
        m = (r + l) / 2;
    }
}