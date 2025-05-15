#include <iostream>
using namespace std;

typedef long long ll;
int n;
ll a1, a2, m1, m2, x, y, d, t;
bool flag = true;

ll exgcd(ll a, ll b, ll &x, ll &y);

int main() {
    scanf("%d", &n);
    scanf("%d%d", &a1, &m1);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a2, &m2);
        d = exgcd(a1, a2, x, y);
        if ((m2 - m1) % d) {
            flag = false;
            break;
        }
        x *= (m2 - m1) / d;
        t = a2 / d;
        x = ((x % t) + t) % t;
        m1 = a1 * x + m1;
        a1 = abs(a1 / d * a2);
    }
    if (flag) printf("%lld", ((m1 % a1) + a1) % a1);
    else printf("-1");
    return 0;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}