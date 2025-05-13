#include <iostream>
using namespace std;

int n, a, res;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        res = a;
        for (int i = 2; i <= a / i; i++) {
            if (!(a % i)) {
                res = res / i * (i - 1);
                while (!(a % i)) a /= i;
            }
        }
        if (a > 1) res = res / a * (a - 1);
        printf("%d\n", res);
    }
    return 0;
}