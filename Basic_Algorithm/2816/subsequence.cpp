#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, i, j, a[N], b[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    for (i = 0, j = 0; j < m; j++) {
        if (a[i] == b[j]) i++;
        if (i == n) break;
    }
    if (i == n) printf("Yes");
    else printf("No");
    return 0;
}