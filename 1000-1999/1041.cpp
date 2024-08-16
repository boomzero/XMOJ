#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,r,c;
int a[20][20];
int ls[20],hs[20][20];
int list[20];
int ans=0x7fffffff;
int f[20][20];
void ldfs(int x,int last,int nowc,int nowsum){
    for(int i=0;i<m;++i)
        for(int j=0;j<=c;++j)
            f[i][j]=1E9;
    for(int i=0;i<m;++i)f[0][0]=0,f[i][1]=ls[i];
    for(int i=1;i<m;++i)
        for(int j=2;j<=c;++j){
            for(int k=0;k<i;++k)f[i][j]=min(f[i][j],f[k][j-1]+hs[k][i]);
            f[i][j]+=ls[i];
        }
    for(int i=0;i<m;++i)ans=min(ans,f[i][c]);
}
void hdfs(int x,int now){
    if(n-x<now)return;
    if(x==n){
        memset(ls,0,sizeof(ls));
        for(int i=m;i--;)
            for(int j=r;--j;)
                ls[i]+=abs(a[list[j]][i]-a[list[j-1]][i]);
        memset(hs,0,sizeof(hs));
        for(int i=0;i<m;++i)
            for(int j=i+1;j<m;++j)
                for(int k=r;k--;)
                    hs[i][j]+=abs(a[list[k]][i]-a[list[k]][j]);
        ldfs(0,m-1,c,0);
        return;
    }
    hdfs(x+1,now);
    if(now){
        list[--now]=x;
        hdfs(x+1,now);
    }
}
int main() {
	freopen("submatrix.in","r",stdin);
	freopen("submatrix.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&r,&c);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",a[i]+j);
    hdfs(0,r);
    printf("%d\n",ans);
}
