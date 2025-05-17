#include <iostream>
using namespace std;

int n, x, res;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (i % 2) res ^= x;
    }
    if (res) printf("Yes");
    else printf("No");
    return 0;
}