#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int n;
int S[100005];
ll sumi[100005];
 
int main() {
freopen("move.in","r",stdin);
freopen("move.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    ll ans = 0;
    for (int AB = 1; AB < n - 2; AB++) {
        for (int i = n - 1 - AB; i > 0; i -= AB) {
            sumi[i] = sumi[i + AB] + S[i];
        }
        ll sumx = 0;
        for (int i = AB; i < n - 1; i += AB) {
            int A = n - 1 - i;
            sumx += S[i];
            if (AB >= A) continue;
            if (A <= i && A % AB == 0) continue;
            ans = max(ans, sumx + sumi[A]);
        }
    }
    cout << ans;
}
