#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n, res, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    for (int i = 0; i < n; i++) res += abs(a[i] - a[n / 2]);
    printf("%d", res);
    return 0;
}