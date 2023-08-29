#include <bits/stdc++.h>

using namespace std;
int n, a[100005], b[100005];
priority_queue<int> sm;
priority_queue<int, vector<int>, greater<>> sp;

signed main() {
    int ans = numeric_limits<int>::min();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            sm.push(a[i]);
        } else {
            sp.push(a[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (sm.empty()) {
            int c = sp.top() + b[i];
            if (ans == numeric_limits<int>::min()) {
                ans = sp.top();
            } else {
                ans ^= sp.top();
            }
            sp.pop();
            if (c < 0) {
                sm.push(c);
            } else {
                sp.push(c);
            }
        } else if (sp.empty()) {
            int c = sm.top() + b[i];
            if (ans == numeric_limits<int>::min()) {
                ans = -sm.top();
            } else {
                ans ^= -sm.top();
            }
            sm.pop();
            if (c < 0) {
                sm.push(c);
            } else {
                sp.push(c);
            }
        } else if (sp.top() <= -sm.top()) {
            int c = sp.top() + b[i];
            if (ans == numeric_limits<int>::min()) {
                ans = sp.top();
            } else {
                ans ^= sp.top();
            }
            sp.pop();
            if (c < 0) {
                sm.push(c);
            } else {
                sp.push(c);
            }
        } else {
            int c = sm.top() + b[i];
            if (ans == numeric_limits<int>::min()) {
                ans = -sm.top();
            } else {
                ans ^= -sm.top();
            }
            sm.pop();
            if (c < 0) {
                sm.push(c);
            } else {
                sp.push(c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

