#include <iostream>
using namespace std;

typedef long long ll;
const int N = 20;
int n, m, res, t, cnt, primes[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", &primes[i]);
    for (int i = 1; i < 1 << m; i++) {
        t = 1, cnt = 0;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                cnt++;
                if ((ll)primes[j] * t > n) {
                    t = 0;
                    break;
                }
                t *= primes[j];
            }
        }
        if (t) {
            if (cnt % 2) res += n / t;
            else res -= n / t;
        }
    }
    printf("%d", res);
    return 0;
}
