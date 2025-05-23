#include <iostream>
using namespace std;

const int N = 1010;
int n, res, a[N], f[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    printf("%d", res);
    return 0;
}