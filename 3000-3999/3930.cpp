#include<bits/stdc++.h>
using namespace std;
const int N=100010;
const long long INF=(1ll)<<(60);
int n,a[N],b[N],aa[N],bb[N],c[N],d[N],e[N],f[N];
long long sum,ans=INF;
inline void update(int x,int k){
    for(;x<=n;x+=x&(-x)) c[x]+=k;
}
inline int query(int x){
    int res=0; for(;x;x-=x&(-x)) res+=c[x];
        return res;
}
void work(int *a,int *b,int *aa,int *bb){
    for(int i=1;i<=n;++i)
        c[i]=d[i]=e[i]=f[i]=0;
    for(int i=1;i<=n;++i)
        b[i]=aa[b[i]];
    for(int i=1;i<=n;++i){
        update(b[i],1);
        d[i]=i-query(b[i]);
    }
    memset(c,0,sizeof(c));
    sum=0;
    for(int i=n;i>=1;--i){
        update(b[i],1);
        e[i]=n-i+1-query(b[i]);
        f[i]=n-i-e[i];
    }
    for(int i=1;i<=n;++i){
        sum+=d[i];
    }
    for(int i=n;i>1;--i){
        sum=sum-d[i]+(i-1-d[i])-e[i]+f[i];
        ans=min(ans,sum);
    }
}
int main(){
	freopen("mincross.in","r",stdin);
	freopen("mincross.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        aa[a[i]]=i;
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&b[i]);
        bb[b[i]]=i;
    }
    work(a,b,aa,bb);
    work(b,a,bb,aa);
    printf("%lld",ans);
    return 0;
}
