#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, r, res = 1;
vector<pair<int, int>> interval;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        interval.emplace_back(l, r);
    }
    sort(interval.begin(), interval.end());
    l = interval[0].first, r = interval[0].second;
    for (int i = 1; i < n; i++) {
        if (interval[i].first > r) {
            res++;
            l = interval[i].first, r = interval[i].second;
        } else if (interval[i].second > r) r = interval[i].second;
    }
    printf("%d", res);
    return 0;
}