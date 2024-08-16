#include<bits/stdc++.h>
#define Ll long long
using namespace std;
const Ll N=2e4+5;
struct cs{int to,nxt,v;}a[N];
int head[N],ll,d[201][N],v[N],ok[N];
bool vi[N];
int n,m,x,y,z,K,q,sum;
Ll s;
void spfa(int v,int S){
    queue<int>Q;
    Q.push(S);d[v][S]=0;
    while(!Q.empty()){
        int x=Q.front();Q.pop();vi[x]=0;
        for(int k=head[x];k;k=a[k].nxt)
            if(d[v][a[k].to]>d[v][x]+a[k].v){
                d[v][a[k].to]=d[v][x]+a[k].v;
                if(!vi[a[k].to])vi[a[k].to]=1,Q.push(a[k].to);
            }
    }
}
void init(int x,int y,int v){
	a[++ll].to=y;a[ll].v=v;a[ll].nxt=head[x];head[x]=ll;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&K,&q);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        init(x,y,z);
    }
    for(int i=1;i<=K;i++)
    	scanf("%d",&v[i]),ok[v[i]]=i;
    memset(d,63,sizeof d);
    for(int i=1;i<=K;i++)
    	spfa(i,v[i]);
    while(q--){
        scanf("%d%d",&x,&y);
        int ans=1e9;
        if(ok[x])
        	ans=d[ok[x]][y];
        else
            for(int k=head[x];k;k=a[k].nxt)
                ans=min(ans,a[k].v+d[ok[a[k].to]][y]);
        if(ans<=2e8)sum++,s+=ans;
    }
    printf("%d\n%lld",sum,s);
}
