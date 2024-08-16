// Memory Limit: 512 MB
// Time Limit: 2000 ms
#include <bits/stdc++.h>
typedef long long ll;
inline ll read() {
    ll x=0;bool flag=true;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') flag=false; ch=getchar();}
    while(isdigit(ch)){ x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
    if(flag) return x;
    return ~(x - 1);
}
const ll maxn=(ll)5e5+5;
ll r[maxn],w[maxn],g[maxn];
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
    ll n=read(),m=read();
    std::mt19937 rng(time(nullptr));
    for(ll u=1;u<=n;++u)
        w[u]=rng();
    ll tar=std::accumulate(w+1,w+n+1,0LL);
    ll now=0;
    while (m--) {
        ll u=read(),v=read();
        r[v]+=w[u];
        g[v]=r[v];
        now+=w[u];
    }
    ll q=read();
    while(q--) {
        ll t=read();
        if(t==1){
            ll u=read(),v=read();
            r[v]-=w[u];
            now-=w[u];
        }
        else if(t==2){
            ll v=read();
            now-=r[v];
            r[v]=0;
        }
        else if(t==3){
            ll u=read(),v=read();
            r[v]+=w[u];
            now+=w[u];
        }
        else if(t==4){
            ll v=read();
            now+=g[v]-r[v];
            r[v]=g[v];
        }
        puts(now==tar?"YES":"NO");
    }
    return 0;
}
