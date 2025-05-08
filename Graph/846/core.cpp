#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, a, b, res = N, idx, h[N], e[2 * N], ne[2 * N];
bool v[N];

void add(int a, int b);
int dfs(int u);

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(1);
    printf("%d", res);
    return 0;
}

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u) {
    int t, sum = 1, ans = 0, s = 0;
    v[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {
        t = e[i];
        if (!v[t]) {
            s = dfs(t);
            ans = max(ans, s);
            sum += s;
        }
    }
    ans = max(ans, n - sum);
    res = min(res, ans);
    return sum;
}