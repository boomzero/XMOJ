#include<bits/stdc++.h>
using namespace std;
int n,k,g[100010],x[100010],w[1000010],maxl,ans;
int main()
{
    freopen("wheat.in","r",stdin);
    freopen("wheat.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&g[i],&x[i]);
        maxl=max(maxl,x[i]);
        w[x[i]]+=g[i];
    }
    if(k<<1>=maxl)
    {
        for(int i=1;i<=n;i++)
            ans+=g[i];
        printf("%d\n",ans);
        return 0;
    }
    for(int i=2;i<=maxl;i++)
        w[i]+=w[i-1];
    maxl-=k;
    for(int i=k;i<=maxl;i++)
        ans=max(ans,w[i+k]-w[i-k-1]);
    printf("%d\n",ans);
    return 0;
}
