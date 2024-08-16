#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T> inline void chmin(T &x,T y){
	if(x>y)
		x=y;
}
template <typename T> inline void chmax(T &x,T y)
{
	if(x<y)
		x=y;
}
int N,M,a[100010],b[100010],c[100010],d[110][110],ans;
int main() {
    scanf("%d%d",&N,&M);
    memset(d,0x3f,sizeof(d));
    for (int i=1;i<=N;++i)
		d[i][i]=0;
    for (int i=1;i<=M;++i) {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        d[a[i]][b[i]]=d[b[i]][a[i]]=c[i];
    }
    for(int k=1;k<=N;++k)
        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
                chmin(d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<=M;++i) {
        int f=1;
        for(int j=1;f&&j<=N;++j)
            if(d[j][b[i]]==d[j][a[i]]+c[i]) f=0;
        // for (int j=1;f&&j<=N;++j)
        //     for (int k=1;f&&k<=N;++k)
        //         if (d[j][k]==d[j][a[i]]+d[b[i]][k]+c[i]) f=0;
        ans+=f;
    }
    printf("%d\n",ans);
    return 0;
}
