#include <iostream>
#include <vector>
using namespace std;

const int N = 5010;
int a, b, idx, primes[N], cnt[N];
bool v[N];
vector<int> res;

void find_primes(int n);
int count_prime(int n, int p);
vector<int> mul(vector<int> &a, int b);

int main() {
    scanf("%d%d", &a, &b);
    find_primes(a);
    for (int i = 0; i < idx; i++) {
        cnt[i] = count_prime(a, primes[i]) - count_prime(b, primes[i]) - count_prime(a - b, primes[i]);
    }
    res.emplace_back(1);
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            res = mul(res, primes[i]);
        }
    }
    for (int i = res.size() - 1; i > -1; i--) printf("%d", res[i]);
   return 0;
}

void find_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!v[i]) primes[idx++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            v[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int count_prime(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> &a, int b) {
    vector<int> c;
    int i = 0, t = 0;
    while (i < a.size() || t) {
        if (i < a.size()) t += a[i++] * b;
        c.emplace_back(t % 10);
        t /= 10;
    }
    return c;
}