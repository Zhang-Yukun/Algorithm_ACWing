#include <iostream>
using namespace std;

int n, t, res;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        res = 0;
        while (t) {
            res += t & 1;
            t >>= 1;
        }
        printf("%d ", res);
    }
    return 0;
}