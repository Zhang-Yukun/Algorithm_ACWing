#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 1e4 + 10;
int n, k, x, res, s[N], f[N];

int sg(int x);

int main() {
    memset(f, -1, sizeof(f));
    scanf("%d", &k);
    for (int i = 0; i < k; i++) scanf("%d", &s[i]);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        res ^= sg(x);
    }
    if (res) printf("Yes");
    else printf("No");
    return 0;
}

int sg(int x) {
    if (f[x] != -1) return f[x];
    unordered_set<int> states;
    for (int i = 0; i < k; i++) {
        if (x >= s[i]) states.insert(sg(x - s[i]));
    }
    for (int i = 0; ; i++) {
        if (!states.count(i)) {
            f[x] = i;
            break;
        }
    }
    return f[x];
}