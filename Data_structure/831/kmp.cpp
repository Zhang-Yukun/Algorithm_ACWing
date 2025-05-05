#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m, ne[N];
char p[N], s[N];

int main() {
    scanf("%d%s%d%s", &n, p, &m, s);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && p[j] != p[i]) j = ne[j - 1];
        if (p[j] == p[i]) j++;
        ne[i] = j;
    }
    for (int i = 0, j = 0; i < m; i++) {
        while (j && p[j] != s[i]) j = ne[j - 1];
        if (p[j] == s[i]) j++;
        if (j == n) {
            printf("%d ", i - j + 1);
            j = ne[j - 1];
        }
    }
    return 0;
}