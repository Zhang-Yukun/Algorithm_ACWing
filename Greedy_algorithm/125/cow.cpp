#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 5e5 + 10;
int n, w, s, res = -1e9 - 10, sum;
pair<int, int> e[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &w, &s);
        e[i] = {w + s, w};
    }
    sort(e, e + n);
    for (int i = 0; i < n; i++) {
        w = e[i].second, s = e[i].first - w;
        res = max(res, sum - s);
        sum += w;
    }
    printf("%d", res);
    return 0;
}