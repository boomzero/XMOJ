#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int rest[1000001],need[1000001],diff[1000001],r[1000001],l[1000001],d[1000001];
bool check(int x)
{
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=x;i++)
    {
        diff[l[i]]+=d[i];
        diff[r[i]+1]-=d[i];
    }
    for(int i=1;i<=n;i++)
    {
        need[i]=need[i-1]+diff[i];
        if(need[i]>rest[i])
            return 0;
    }
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&rest[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&d[i],&l[i],&r[i]);
    int ll=1;
    int rr=m;
    if(check(m))
    {
        printf("0");
        return 0;
    }
    while(ll<rr)
    {
        int mid=(ll+rr)>>1;
        if(check(mid))
            ll=mid+1;
        else
            rr=mid;
    }
    printf("-1\n%d",ll);
    return 0;
}
