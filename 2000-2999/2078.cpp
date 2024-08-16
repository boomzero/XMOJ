#include<bits/stdc++.h>
bool IOerror = 0;
inline char nc() {
    static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
    if(p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, 100000, stdin);
        if(pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
    char ch;
    while(blank(ch = nc()));
    if(IOerror)
        return;
    for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
}
using namespace std;
typedef long long ll;
const int maxa=200005;
const int maxn=500005;
bool vis[maxn];
int prim[maxn];
int mu[maxn];
int cnt;
void get_mu(int n){
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            prim[++cnt]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cnt && prim[j]*i<=n;j++){
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break;
            else mu[i*prim[j]]=-mu[i];
        }
    }
}
int n,q;
int a[maxa];
bool in[maxa];
int c[maxn];
vector<int> g[maxn];
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
    get_mu(maxn-1);
    for(int i=1;i<maxn;++i){
        for(int j=i;j<maxn;j+=i){
            g[j].push_back(i);
        }
    }
    read(n);read(q);
    for(int i=1;i<=n;++i) read(a[i]);
    ll ans=0;
    while(q--){
        int id,x;
        read(id);
        x=a[id];
        if(!in[id]){
            int num=g[x].size();
            for(int i=0;i<num;++i){
                int u=g[x][i];
                ans+=mu[u]*c[u];
                ++c[u];
            }
        }
        else{
            int num=g[x].size();
            for(int i=0;i<num;++i){
                int u=g[x][i];
                --c[u];
                ans-=mu[u]*c[u];
            }
        }
        in[id]=!in[id];
        printf("%lld\n",ans);
    }
    return 0;
}

