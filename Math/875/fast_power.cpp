#include <iostream>
using namespace std;

int n;
long long a, b, p, res;

long long fast_power(long long a, long long b, long long p);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d", &a, &b, &p);
        res = fast_power(a, b, p);
        printf("%d\n", res);
    }
    return 0;
}

long long fast_power(long long a,long long b, long long p) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
