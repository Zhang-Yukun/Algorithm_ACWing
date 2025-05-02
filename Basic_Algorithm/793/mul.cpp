#include <iostream>
#include <vector>
using namespace std;

string sa;
vector<int> a, c;
int b;

vector<int> mul(vector<int> &a, int b);

int main() {
    cin >> sa;
    scanf("%d", &b);
    for (int i = sa.size() - 1; i > -1; i--) a.emplace_back(sa[i] - '0');
    c = mul(a, b);
    for (int i = c.size() - 1; i > -1; i--) printf("%d", c[i]);
    return 0;
}

vector<int> mul(vector<int> &a, int b) {
    int t = 0, i = 0;
    while (i < a.size() || t) {
        if (i < a.size()) t += a[i++] * b;
        c.emplace_back(t % 10);
        t /= 10;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}