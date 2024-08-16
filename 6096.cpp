#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;
unsigned long long r[1000005];
unsigned long long p[1000005];
map <unsigned long long,int> d;
int n,m,x,y;
long long ans;
int main()
{
    srand(19260817);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) r[i]=1ll*rand()*rand()*rand()*rand()*rand();
    for(int i=1;i<=m;i++)
      scanf("%d%d",&x,&y),p[x]^=r[y],p[y]^=r[x];
    for(int i=1;i<=n;i++){
        ans+=d[p[i]];
        d[p[i]]++;
    }
    d.clear();
    for(int i=1;i<=n;i++) p[i]^=r[i];
    for(int i=1;i<=n;i++){
        ans+=d[p[i]];
        d[p[i]]++;
    }
    printf("%lld",ans);
}
