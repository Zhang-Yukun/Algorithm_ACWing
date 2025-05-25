#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, l, r, s, t, res;
struct Interval{
    int l, r;
    bool operator < (const struct Interval &interval) {
        return l < interval.l;
    }
} e[N];

int main() {
    scanf("%d%d%d", &s, &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        e[i] = {l, r};
    }
    sort(e, e + n);
    for (int i = 0, j = 0; i < n; i++) {
        r = -1e9 - 10;
        while (j < n && e[j].l <= s) {
            r = max(r, e[j++].r);
        }
        if (r < s) break;
        res++;
        if (r >= t) break;
        s = r;
        i = j - 1;
    }
    if (r < t) res = -1;
    printf("%d", res);
    return 0;
}