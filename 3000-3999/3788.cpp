#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch)) f|=ch=='-',ch=getchar();
    while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=2005,V=105;
int n,m,L,s[N],pre[N];
vector <int> c[V];
bitset <N> dp[N],st[15],ans;
int main()
{
    freopen("cup.in","r",stdin);
    freopen("cup.out","w",stdout);
    n=read(),L=read();
    for (int i=1;i<=n;++i) {
        int C=read(),v=read();
        c[v].push_back(C);
    }
    m=read();
    for (int i=1;i<=m;++i) s[i]=read();
    dp[0][0]=1;
    for (int v=1;v<=100;++v) {
        if (c[v].empty()) continue;
        sort(c[v].begin(),c[v].end(),greater<int>());
        int len=c[v].size();
        pre[0]=0;
        for (int i=0;i<len;++i) pre[i+1]=pre[i]+c[v][i];
        for (int i=n-1;i>=0;--i) {
            st[0]=dp[i];
            for (int j=1;j<=10;++j)
                st[j]=(st[j-1]<<(v<<(j-1)))|st[j-1];
            for (int j=1;j<=len&&i+j<=n;++j) {
                int now=min(pre[j]-j+1,L/v),d=log(now)/log(2);
                dp[i+j]|=(st[d]<<(v*(now-(1<<d)))|st[d])<<(v*j);
            }
        }
    }
    for (int i=1;i<=m;++i) ans|=dp[s[i]];
    for (int i=0;i<=L;++i)
        if (ans[i])
            printf("%d ",i);
    puts("");
    return 0;
}
