#include <iostream>
using namespace std;

int n, a, b;

int gcd(int a, int b);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}