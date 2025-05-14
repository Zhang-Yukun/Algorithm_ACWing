#include <iostream>
using namespace std;

int n, a, b, x, y;

int exgcd(int a, int b, int &x, int &y);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
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