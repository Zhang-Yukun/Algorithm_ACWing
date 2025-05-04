#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, x, t, s[N];

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        while (t && s[t - 1] >= x) t--;
        if (!t) printf("%d ", -1);
        else printf("%d ", s[t - 1]);
        s[t++] = x;
    }
    return 0;
}