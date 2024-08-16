#include<cstdio>
#include<algorithm>
#define mod 99999997
using namespace std;
struct node
{
    int h,order;
}a[100010],b[100010];
int c[100010],sum[100010],n,ans;
bool cmp(node a,node b)
{
    return a.h<b.h;
}
void fix(int x)
{
    for(int i=x;i<=n;i+=i&-i)
        c[i]++,c[i]%=mod;
}
int getsum(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)
        ret+=c[i],ret%=mod;
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].h);
        a[i].order=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i].h);
        b[i].order=i;
    }
    sort(b+1,b+n+1,cmp);
    for(int i=1;i<=n;i++)
        sum[a[i].order]=b[i].order;
    for(int i=1;i<=n;i++)
    {
        fix(sum[i]);
        ans+=i-getsum(sum[i]);
        ans%=mod;
    }
    printf("%d",ans);
    return 0;
}
