#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, l, r, res;
struct Interval{
    int l, r;
    bool operator < (const struct Interval &interval) {
        return r < interval.r;
    }
} e[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        e[i] = {l, r};
    }
    sort(e, e + n);
    r = e[0].r, res++;
    for (int i = 1; i < n; i++) {
        if (r < e[i].l) res++, r = e[i].r;
    }
    printf("%d", res);
    return 0;
}