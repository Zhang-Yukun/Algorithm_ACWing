#include <iostream>
#include <vector>
using namespace std;

string sa, sb;
vector<int> a, b, c;

vector<int> add(vector<int> &a, vector<int> &b);

int main() {
    cin >> sa >> sb;
    for (int i = sa.size() - 1; i > -1; i--) a.emplace_back(sa[i] - '0');
    for (int i = sb.size() - 1; i > -1; i--) b.emplace_back(sb[i] - '0');
    c = add(a, b);
    for (int i = c.size() - 1; i > -1; i--) printf("%d", c[i]);
    return 0;
}

vector<int> add(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int i = 0, t = 0;
    while (i < a.size() || i < b.size() || t) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        i++;
        c.emplace_back(t % 10);
        t /= 10;
    }
    return c;
}
