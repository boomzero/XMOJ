#include <bits/stdc++.h>

using namespace std;
int n, cnt = 0, ss = 0, arr[50] = {0};

void dfs(int v) {
    ss++;
    arr[ss] = v;
    if (v > n) {
        ss--;
        return;
    }
    if (v == n) {
        cnt++;
        cout << cnt << " ";
        bool f = true;
        for (int i = 1; i <= ss; ++i) {
            if (!f) cout << ">";
            f = false;
            cout << arr[i];
        }
        cout << endl;
        ss--;
        return;
    }
    dfs(v + 1);
    dfs(v + 2);
    ss--;
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}



