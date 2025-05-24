#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, l, r;
struct Interval{
    int l, r;
    bool operator < (const struct Interval &interval) {
        return l < interval.l;
    }
} e[N];
priority_queue<int, vector<int>, greater<int>> heap;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        e[i] = {l, r};
    }
    sort(e, e + n);
    for (int i = 0; i < n; i++) {
        if (heap.empty() || heap.top() >= e[i].l) heap.push(e[i].r);
        else heap.pop(), heap.push(e[i].r);
    }
    printf("%d", heap.size());
    return 0;
}