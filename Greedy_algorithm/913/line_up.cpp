#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n, t[N];
ll res;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", t + i);
    sort(t, t + n);
    for (int i = 1; i < n; i++) res += t[i - 1] * (n - i);
    printf("%lld", res);
    return 0;
}