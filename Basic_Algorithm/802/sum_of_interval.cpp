#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n, m, x, c, l, r, t, a[3 * N], s[3 * N];
pair<int, int> op[N], q[N];
vector<int> map;

vector<int>::iterator unique_array(vector<int> &v);
int find(vector<int> &v, int x);

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &c);
        op[i] = {x, c};
        map.emplace_back(x);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        q[i] = {l, r};
        map.emplace_back(l);
        map.emplace_back(r);
    }
    sort(map.begin(), map.end());
    map.erase(unique_array(map), map.end());
    for (int i = 0; i < n; i++) a[find(map, op[i].first)] += op[i].second;
    for (int i = 1; i <= map.size(); i++) s[i] = s[i - 1] + a[i];
    for (int i = 0; i < m; i++) {
        printf("%d\n", s[find(map, q[i].second)] - s[find(map, q[i].first) - 1]);
    }
    return 0;
}

vector<int>::iterator unique_array(vector<int> &v) {
    int i = 0, j = 0;
    while (j < v.size()) {
        while (j != 0 && v[j] == v[j - 1]) j++;
        v[i++] = v[j++];
    }
    return v.begin() + i;
}

int find(vector<int> &v, int x) {
    int l = 0, r = v.size() - 1, m = (l + r) >> 1;
    while (l <= r) {
        if (v[m] == x) return m + 1;
        else if (v[m] < x) l = m + 1;
        else r = m - 1;
        m = (l + r) >> 1;
    }
    return -1;
}
