#include <iostream>
#include <vector>
using namespace std;

string sa, sb;
vector<int> a, b, c;

bool cmp(vector<int> &a, vector<int> &b);
vector<int> sub(vector<int> &a, vector<int> &b);

int main() {
    cin >> sa >> sb;
    for (int i = sa.size() - 1; i > -1; i--) a.emplace_back(sa[i] - '0');
    for (int i = sb.size() - 1; i > -1; i--) b.emplace_back(sb[i] - '0');
    if (cmp(a, b)) {
        c = sub(a, b);
        for (int i = c.size() - 1; i > -1; i--) printf("%d", c[i]);
    } else {
        c = sub(b, a);
        printf("-");
        for (int i = c.size() - 1; i > -1; i--) printf("%d", c[i]);
    }
    return 0;
}

bool cmp(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) return a.size() > b.size();
    else {
        for (int i = a.size() - 1; i > -1; i--) {
            if (a[i] != b[i]) return a[i] > b[i];
        }
    }
    return true;
}

vector<int> sub(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int t = 0, i = 0;
    while (i < b.size()) {
        t += (a[i] - b[i++]);
        c.emplace_back((t + 10) % 10);
        if (t < 0) t = -1;
        else t = 0;
    }
    while (i < a.size()) {
        t += a[i++];
        c.emplace_back((t + 10) % 10);
        if (t < 0) t = -1;
        else t = 0;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
