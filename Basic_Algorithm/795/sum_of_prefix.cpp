#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, l, r, t, s[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        s[i] = s[i - 1] + t;
    }
    while (m--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}