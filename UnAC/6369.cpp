#include <bits/stdc++.h>
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
typedef long long ll;
using namespace std;
ll testSet[] = {2, 3,7,11};
long long powMod(long long a, long long b, long long mode) {
    long long sum = 1;
    while (b) {
        if (b & 1) {
            sum = (sum * a) % mode;
            b--;
        }
        b /= 2;
        a = a * a % mode;
    }
    return sum;
}
int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        ll n;
        cin >> n;
        if (n == 2) {
            Yes
            continue;
        }
        ll r = 0, d = n - 1;
        while (d % 2 == 0) {
            r++;
            d /= 2;
        }
        bool passTest = false, pa = true;
        for (ll a: testSet) {
            ll i = 1;
            passTest = false;
            while (i <= r) {
                if (powMod(a, d * (1 << i), n) == 1) {
                    passTest = true;
                    break;
                }
                i++;
            }
            if (!passTest) {
                No
                pa= false;
                break;
            }
        }
        if(pa) Yes
    }
    return 0;
}
