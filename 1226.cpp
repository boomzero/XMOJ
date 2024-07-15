#include <bits/stdc++.h>

using namespace std;
int n, k, diff[1000005] = {0};
int arr[1000005] = {0};

int main() {
    freopen("brick.in", "r", stdin);
    freopen("brick.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        int a, b;
        cin >> a >> b;
        diff[a]++;
        diff[b + 1]--;
    }
    arr[1] = diff[1];
    for (int i = 2; i <= n; ++i) {
        arr[i] = arr[i - 1] + diff[i];
    }
    sort(arr + 1, arr + n + 1);
    cout << arr[n / 2 + 1] << endl;
    return 0;
}
