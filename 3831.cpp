#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void cmax(ll &x,ll y) { if (x<y) x=y; }
int main() {
    freopen("c.in","r",stdin) ;
    freopen("c.out","w",stdout) ;
    ll n,m; cin>>n>>m;
    ll res=1;
    for (int i=1;i*i<=m;++i) {
        if (m%i==0&&i*n<=m) {
            cmax(res, i);
            if ((m/i)*n<=m)
                cmax(res,m/i);
        }
    }
    cout<<res<<endl;
    return 0;
}
