#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<>> rocks;
    for (int i = 0; i < n; ++i) {
        long long tmp;
        cin >> tmp;
        rocks.push(tmp);
    }
    long long ans = 0;
    while (rocks.size() > 1) {
        long long s = 0;
        ans += rocks.top();
        s += rocks.top();
        rocks.pop();
        ans += rocks.top();
        s += rocks.top();
        rocks.pop();
        rocks.push(s);
    }
    cout << ans << endl;
    return 0;
}

