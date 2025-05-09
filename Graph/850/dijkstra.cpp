#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int n, m, x, y, z, idx, d[N], h[N], e[N], w[N], ne[N];
bool v[N];

void add(int a, int b, int c);
int dijkstra(int n);

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    printf("%d", dijkstra(n));
    return 0;
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(int n) {
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    pair<int, int> p;
    int distance, node;
    heap.push({0, 1});
    while (!heap.empty()) {
        p = heap.top();
        heap.pop();
        distance = p.first, node = p.second;
        if (v[node]) continue;
        v[node] = true;
        for (int i = h[node]; i != -1; i = ne[i]) {
            if (d[node] + w[i] < d[e[i]]) {
                d[e[i]] = d[node] + w[i];
                heap.push({d[e[i]], e[i]});
            }
        }
    }
    if (d[n] == 0x3f3f3f3f) return -1;
    else return d[n];
}