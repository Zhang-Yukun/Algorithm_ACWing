#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int n, l, r, res;
vector<pair<int, int>> interval;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &l, &r);
        interval.emplace_back(l, r);
    }
    sort(interval.begin(), interval.end());
    l = interval[0].first, r = interval[0].second, res = 1;
    for (int i = 1; i < interval.size(); i++) {
        if (interval[i].first > r) {
            res++;
            l = interval[i].first, r = interval[i].second;
        } else if (interval[i].second > r) r = interval[i].second;
    }
    printf("%d", res);
    return 0;
}