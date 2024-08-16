#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 50050
#define M 150050
typedef long long ll;
ll f[N][11],mn[N][11],mx[N][11];
int head[N],to[M],nxt[M],cnt,val[M],Q[N],l,r,in[N],n,m,K;
inline void add(int u,int v,int w) {
    to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; val[cnt]=w;
}
int main() {
    scanf("%d%d%d",&n,&m,&K);
    int i,x,y,z,j;
    for(i=1;i<=m;i++) {
        scanf("%d%d%d",&x,&y,&z); add(y,x,z); in[x]++;
    }
    for(i=0;i<=K;i++) f[n][i]=0;
    memset(mn,0x3f,sizeof(mn));
    Q[r++]=n;
    while(l<r) {
        x=Q[l++];
        for(i=0;i<=K;i++)
        	f[x][i]=min(mx[x][i],mn[x][i]);
        for(i=head[x];i;i=nxt[i]){
            for(j=0;j<=K;j++)
            	mx[to[i]][j]=max(mx[to[i]][j],f[x][j]+val[i]);
            for(j=0;j<K;j++)
            	mn[to[i]][j]=min(mn[to[i]][j],f[x][j+1]+val[i]);
            if((--in[to[i]])==0)
            	Q[r++]=to[i];
        }
    }
    printf("%lld\n",f[1][0]);
}
