#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10, MOD = 1e9 + 7;

int n, a, b, factor[N], ifactor[N];

int binpow(int a, int b, int p);

int main() {
    factor[0] = ifactor[0] = 1;
    for (int i = 1; i < N; i++) {
        factor[i] = ((ll)factor[i - 1] * i) % MOD;
        ifactor[i] = ((ll)ifactor[i - 1] * binpow(i, MOD - 2, MOD)) % MOD;
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", ((((ll)factor[a] * ifactor[b]) % MOD) * ifactor[a - b]) % MOD);
    }
    return 0;
}

int binpow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = ((ll) res * a) % p;
        a = ((ll) a * a) % p;
        b >>= 1;
    }
    return res;
}