#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t;
vector<int> divisors;

vector<int> find_divisors(int n);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        divisors = find_divisors(t);
        for (int i = 0; i <divisors.size(); i++) printf("%d ", divisors[i]);
        printf("\n");
    }
    return 0;
}

vector<int> find_divisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n / i; i++) {
        if (!(n % i)) {
            divisors.emplace_back(i);
            if (i != n / i) divisors.emplace_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}