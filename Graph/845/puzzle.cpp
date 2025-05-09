#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

string s;
char c[2];

int bfs(string &s);

int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%s", c);
        s += c[0];
    }
    printf("%d", bfs(s));
    return 0;
}

int bfs(string &s) {
    string end = "12345678x", node;
    unordered_map<string, int> d;
    queue<string> q;
    int pos_x, x, y, a, b, distance, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        distance = d[node];
        if (node == end) return distance;
        pos_x = node.find('x');
        x = pos_x / 3, y = pos_x % 3;
        for (int i = 0; i < 4; i++) {
            a = x + dx[i];
            b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(node[pos_x], node[a * 3 + b]);
                if (!d.count(node)) {
                    q.push(node);
                    d[node] = distance + 1;
                }
                swap(node[pos_x], node[a * 3 + b]);
            }
        }
    }
    return -1;
}