#include <iostream>
#include <vector>

using namespace std;

string sa, sb;
vector<int> a, b, c;

void add(vector<int> &a, vector<int> &b);

int main() {
    cin>>sa>>sb;
    for (int i = sa.size() - 1; i > -1; i--) a.emplace_back(sa[i] - '0');
    for (int i = sb.size() - 1; i > -1; i--) b.emplace_back(sb[i] - '0');
    add(a, b);
    for (int i = c.size() - 1; i > -1; i--) printf("%d", c[i]);
    return 0;
}

void add(vector<int> &a, vector<int> &b) {
    if (a.size() < b.size()) return add(b, a);
    int t = 0, i = 0;
    while (i < b.size()) {
        t += (a[i] + b[i++]);
        c.emplace_back(t % 10);
        t /=10;
    }
    while (i < a.size()) {
        t += a[i++];
        c.emplace_back(t % 10);
        t /= 10;
    }
    if (t) c.emplace_back(t);
}