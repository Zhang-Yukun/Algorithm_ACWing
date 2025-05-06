#include <iostream>
using namespace std;

const int N = 10;
int n, a[N];
bool v[N];

void dfs(int u);

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}

void dfs(int u) {
    if (u == n + 1) {
        for (int i = 1; i <= n; i++) printf("%d ", a[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            a[u] = i;
            v[i] = true;
            dfs(u + 1);
            v[i] = false;
        }
    }
}