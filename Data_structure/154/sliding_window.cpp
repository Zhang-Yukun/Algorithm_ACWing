#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, k, h, t, a[N], q[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    h = t = 0;
    for (int i = 0; i < n; i++) {
        while (h < t && q[h] < i - k + 1) h++;
        while (h < t && a[q[t - 1]] >= a[i]) t--;
        q[t++] = i;
        if (i >= k - 1) printf("%d ", a[q[h]]);
    }
    printf("\n");
    h = t = 0;
    for (int i = 0; i < n; i++) {
        while (h < t && q[h] < i - k + 1) h++;
        while (h < t && a[q[t - 1]] <= a[i]) t--;
        q[t++] = i;
        if (i >= k - 1) printf("%d ", a[q[h]]);
    }
    return 0;
}