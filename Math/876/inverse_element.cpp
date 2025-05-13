#include <iostream>
using namespace std;

int n;
long long a, p, res;

long long fast_power(long long a, long long b, long long p);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &p);
        if (!(a % p)) printf("impossible\n");
        else printf("%d\n", fast_power(a, p - 2, p));
    }
    return 0;
}

long long fast_power(long long a, long long b, long long p) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}