#include <bits/stdc++.h>

using namespace std;
const int mn = 50050;
typedef pair<int, int> pii;

int main() {
    int n, arr[mn];
    cin >> n;
    int rmn = n;
    priority_queue<pii> pq;
    priority_queue<int, vector<int>, greater<>> ans;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pq.emplace(arr[i], i);
    }
    while (rmn > 0) {
        int c = pq.top().second, v = pq.top().first, vb = v;
        pq.pop();
        if (arr[c] == -1) continue;
        ans.push(c);
        arr[c] = -1;
        rmn--;
        for (int i = c + 1; i <= n; ++i) {
            if (arr[i] != -1 && arr[i] < v) {
                rmn--;
                v = arr[i];
                arr[i] = -1;
            } else break;
        }
        v = vb;
        for (int i = c - 1; i >= 1; --i) {
            if (arr[i] != -1 && arr[i] < v) {
                rmn--;
                v = arr[i];
                arr[i] = -1;
            } else break;
        }
    }
    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}

