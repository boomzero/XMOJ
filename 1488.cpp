#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int arr[1500] = {0}, sa[1500] = {0};
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        sa[i] = arr[i];
    }
    sort(sa + 1, sa + 1 + n);
    int c = 0;
    for (int i = 1; i <= n; i++) {
        c++;
        if (!m.count(sa[i])) {
            m[sa[i]] = c;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << m[arr[i]] << " ";
    }
    cout << endl;
    return 0;
}
