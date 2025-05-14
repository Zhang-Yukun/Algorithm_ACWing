#include <iostream>
using namespace std;

int n, a, b, m, x, y, d;

int exgcd(int a, int b, int &x, int &y);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d", &a, &b, &m);
        d = exgcd(a, m, x, y);
        if (b % d) printf("impossible\n");
        else printf("%d\n", ((long long)x * (b / d)) % m);
    }
    return 0;
}

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}