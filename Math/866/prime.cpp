#include <iostream>
using namespace std;

int n, a;

bool is_prime(int x);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (is_prime(a)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) {
        if (!(x % i)) return false;
    }
    return true;
}