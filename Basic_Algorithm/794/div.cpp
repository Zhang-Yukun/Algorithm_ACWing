#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string sa;
vector<int> a, c;
int b, r;

vector<int> div(vector<int> &a, int b, int &r);

int main() {
    cin >> sa;
    scanf("%d", &b);
    for (int i = sa.size() - 1; i > -1; i--) a.emplace_back(sa[i] - '0');
    c = div(a, b, r);
    for (int i = c.size() - 1; i > -1; i--) printf("%d", c[i]);
    printf("\n%d", r);
    return 0;
}

vector<int> div(vector<int> &a, int b, int &r) {
    vector<int> c;
    for (int i = a.size() - 1; i > -1; i--) {
        r = r * 10 + a[i];
        c.emplace_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && !c.back()) c.pop_back();
    return c;
}