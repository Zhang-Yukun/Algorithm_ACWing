#include <iostream>
using namespace std;

int n, t;

void decompose_prime_factor(int x);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        decompose_prime_factor(t);
    }
    return 0;
}

void decompose_prime_factor(int x) {
    int cnt = 0;
    for (int i = 2; i <= x / i; i++) {
        if (!(x % i)) {
            cnt = 0;
            while (!(x % i)) cnt++, x /= i;
            printf("%d %d\n", i, cnt);
        }
    }
    if (x > 1) printf("%d %d\n", x, 1);
    printf("\n");
}