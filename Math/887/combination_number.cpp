#include <iostream>
using namespace std;

typedef long long ll;
int n, p;
ll a, b;

int binpow(int a, int b, int p);
int combination(int a, int b, int p);
int lucas(ll a, ll b, int p);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%lld%lld%d", &a, &b, &p);
        printf("%d\n", lucas(a, b, p));
    }
    return 0;
}

int binpow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = (ll) res * a % p;
        a = (ll) a * a % p;
        b >>= 1;
    }
    return res;
}

int combination(int a, int b, int p) {
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (ll) res * j % p * binpow(i, p - 2, p) % p;
    }
    return res;
}

int lucas(ll a, ll b, int p) {
    if (a < p && b < p) return combination(a, b, p);
    else return (ll)combination(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}