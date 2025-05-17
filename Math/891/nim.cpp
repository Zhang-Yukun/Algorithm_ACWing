#include <iostream>
using namespace std;

int n, x, res;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        res ^= x;
    }
    if (res) printf("Yes");
    else printf("No");
    return 0;
}