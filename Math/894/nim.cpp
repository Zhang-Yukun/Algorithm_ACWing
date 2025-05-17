#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 110;
int n, a, res, f[N];

int sg(int x);

int main() {
    memset(f, -1, sizeof(f));
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        res ^= sg(a);
    }
    if (res) printf("Yes");
    else printf("No");
    return 0;
}

int sg(int x) {
    if (f[x] != -1) return f[x];
    unordered_set<int> s;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            s.insert(sg(i) ^ sg(j));
        }
    }
    for (int i = 0; ; i++) {
        if (!s.count(i)) {
            return f[x] = i;
        }
    }
}