#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, cnt, tv, tw, s, v[N], w[N], f[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &tv, &tw, &s);
        for (int k = 1; k <= s; k *= 2) {
            v[cnt] = k * tv;
            w[cnt++] = k * tw;
            s -= k;
        }
        if (s) v[cnt] = s * tv, w[cnt++] = s * tw;
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d", f[m]);
    return 0;
}