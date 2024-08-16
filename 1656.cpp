#include<bits/stdc++.h>
using namespace std;typedef long long ll;
const int maxn = 1e7;
int mod = 911451407;
int re[maxn + 10], inv[maxn + 10], fac[maxn + 10];
inline void init(int n) {
    re[0] = inv[1] = fac[0] = re[1] = fac[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fac[i] = (ll)fac[i - 1] * i % mod;
        inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
        re[i] = (ll)re[i - 1] * inv[i] % mod;   
    }
}
inline int C(int a,int b) {
    if (a < 0) return 0;
    return (ll)fac[a] * re[b] % mod * re[a - b] % mod;
}

int main(){
    int n;
    cin>>mod>>n;
    init(maxn);
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<C(a,b)<<endl;
    }
    return 0;
}
