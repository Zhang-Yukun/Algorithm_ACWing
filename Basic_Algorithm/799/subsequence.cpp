#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, res, a[N], cnt[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0, j = 0; i < n; i++) {
        cnt[a[i]]++;
        while (cnt[a[i]] > 1) cnt[a[j++]]--;
        res = max(res, i - j + 1);
    }
    printf("%d", res);
    return 0;
}