#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int n, res = 1;

int binpow(ll a, ll b, int p);

int main() {
    scanf("%d", &n);
    for (int i = 1, j = 2 * n; i <= n; i++, j--) {
        res = (ll) res * j % MOD * binpow(i, MOD - 2, MOD) % MOD;
    }
    res = (ll)res * binpow(n + 1, MOD - 2, MOD) % MOD;
    printf("%d", res);
    return 0;
}

int binpow(ll a, ll b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return res;
}