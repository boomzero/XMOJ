#include <bits/stdc++.h>

using namespace std;
long long a[100001] = {0};

int main() {
    freopen("flip.in", "r", stdin);
    freopen("flip.out", "w", stdout);
    long long n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += llabs(a[i]);
    }
    long long minusCnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < 0) {
            minusCnt++;
        }
    }
    if (minusCnt%2==0) cout<<sum<<endl;
    else{
        long long min=numeric_limits<long long>::max();
        for (int i = 1; i <= n; ++i) {
            if (llabs(a[i])<min) min=llabs(a[i]);
        }
        cout<<sum-(2*min)<<endl;
    }
    return 0;
}
