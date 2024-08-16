#include <bits/stdc++.h>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
#define repeat_reverse(i,n) for (int i = (n)-1; (i) >= 0; --(i))
typedef long long ll;
template <class T> bool setmax(T & l, T const & r) {
    if (not (l < r))
        return false;
    l = r;
    return true;
}
using namespace std;
vector<int> min_prime(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= n; ++i)
        if (is_prime[i])
            for (int k = i+i; k <= n; k += i)
                is_prime[k] = false;
    vector<int> primes;
    for (int i = 2; i <= n; ++i)
        if (is_prime[i])
            primes.push_back(i);
    return primes;
}
vector<ll> fct(ll n, vector<int> const & primes) {
    vector<ll> result;
    for (ll p : primes) {
        if (n < p * p) break;
        while (n % p == 0) {
            result.push_back(p);
            n /= p;
        }
    }
    if (n != 1)
        result.push_back(n);
    return result;
}
int main() {
	freopen("pfactor.in", "r", stdin);
	freopen("pfactor.out", "w", stdout);
    ll l, h; cin >> l >> h;
    vector<int> primes = min_prime(sqrt(h) * 10);
    pair<ll,ll> ans = { -1, -1 };
    repeat_reverse (i,primes.size()) {
        ll p = primes[i];
        repeat_from (j,i,min<int>(i+1000,primes.size())) {
            ll q = primes[j];
            if (l <= p * q and p * q <= h) {
                setmax(ans, make_pair(p, p * q));
            }
        }
        if (ans.second != -1)
            break;
    }
    if (ans.second == -1 || h - l + 1 < 10000) {
        for (ll n = l; n < h+1; ++ n) {
            vector<ll> fs = fct(n, primes);
            if (fs.size() != 1) {
                setmax(ans, make_pair(fs.front(), n));
            }
        }
    }
    cout << ans.second << endl;
    return 0;
}
