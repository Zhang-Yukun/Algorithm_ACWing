#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, x, y, res;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        q.push(x);
    }
    while (q.size() > 1) {
        x = q.top(), q.pop();
        y = q.top(), q.pop();
        res += x + y;
        q.push(x + y);
    }
    printf("%d", res);
    return 0;
}