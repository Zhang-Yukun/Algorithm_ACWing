#include <iostream>
using namespace std;

const double EPSILON = 1e-9;
double n;

double cube_root(double n);

int main() {
    scanf("%lf", &n);
    printf("%.6f", cube_root(n));
    return 0;
}

double cube_root(double n) {
    double l = -100, r = 100, m = (l + r) / 2, res = m * m * m;
    while (l <= r) {
        if (res - n < EPSILON && res - n > -EPSILON) return m;
        else if (res < n) l = m;
        else r = m;
        m = (l + r) / 2;
        res = m * m * m;
    }
}
