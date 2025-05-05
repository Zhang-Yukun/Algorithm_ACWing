#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, x, i, j, a[N], b[N];

int main() {
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    for (i = 0, j = m - 1; i < n; i++) {
        while (a[i] + b[j] > x) j--;
        if (a[i] + b[j] == x) break;
    }
    printf("%d %d", i, j);
    return 0;
}