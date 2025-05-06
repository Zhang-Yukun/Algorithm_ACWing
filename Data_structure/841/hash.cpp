#include <iostream>
using namespace std;

const int N = 1e5 + 10, P = 131;
int n, m, l1, r1, l2, r2;
char s[N];
unsigned long long h[N], p[N];

unsigned long long find_hash(int l, int r);

int main() {
    scanf("%d%d%s", &n, &m, s + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i] - '0' + 1;
    }
    while (m--) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (find_hash(l1, r1) == find_hash(l2, r2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

unsigned long long find_hash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}