#include <iostream>
#include <vector>
using namespace std;

int a, b;

int get_num(vector<int> &v, int l, int r);
int power10(int x);
int count(int x, int p);

int main() {
    scanf("%d%d", &a, &b);
    while (a || b) {
        if (a < b) swap(a, b);
        for (int i = 0; i < 10; i++) {
            printf("%d ", count(a, i) - count(b - 1, i));
        }
        printf("\n");
        scanf("%d%d", &a, &b);
    }
    return 0;
}

int get_num(vector<int> &v, int r, int l) {
    int res = 0;
    for (int i = r; i >= l; i--) res = res * 10 + v[i];
    return res;
}

int power10(int x) {
    int res = 1;
    while (x > 0) res *= 10, x --;
    return res;
}

int count(int x, int p) {
    if (!x) return 0;
    int cnt = 0;
    vector<int> v;
    while (x) {
        v.emplace_back(x % 10);
        x /= 10;
    }
    for (int i = v.size() - 1 - !p; i > -1; i--) {
        if (i < v.size() - 1) {
            cnt += get_num(v, v.size() - 1, i + 1) * power10(i);
            if (!p) cnt -= power10(i);
        }
        if (p == v[i]) cnt += get_num(v, i - 1, 0) + 1;
        else if (p < v[i]) cnt += power10(i);
    }
    return cnt;
}