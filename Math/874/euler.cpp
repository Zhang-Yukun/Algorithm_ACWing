#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, cnt, primes[N], phi[N];
long long res;
bool v[N];

int main() {
    scanf("%d", &n);
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            v[primes[j] * i] = true;
            if (!(i % primes[j])) {
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
            phi[i * primes[j]] = (primes[j] - 1) * phi[i];
        }
    }
    for (int i = 1; i <= n; i++) res += phi[i];
    printf("%lld", res);
}