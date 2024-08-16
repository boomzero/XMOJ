#include <cstdio>
#include <iostream>
#include <cstring>
#define N 1000010
using namespace std;
int fun[N],a,b;
long long f[N][2];
struct node
{
    int next,to,v;
}e[2000010];
int st[1000010],vis[N],n,s,tot,x1,x2,E;
void add(int x,int y)
{
    e[tot].to=y,e[tot].next=st[x],st[x]=tot++;
    //e[++tot].to=x,e[tot].v=z,e[tot].next=st[y],st[y]=tot;
}
void find_circle(int x,int pre)
{
    vis[x]=1;
    for (int i=st[x];~i;i=e[i].next)
    {
        if ((i^1)==pre) continue;
        if (vis[e[i].to])
        {
            x1=x,x2=e[i].to;
            E=i;
            continue;
        }
        find_circle(e[i].to,i);
    }
}
void dfs(int x,int pre)
{
    f[x][0]=0;
    f[x][1]=fun[x];
    for (int i=st[x];~i;i=e[i].next)
    {
        if ((i^1)==pre) continue;
        if (i==E || (i^1)==E)
            continue;
        dfs(e[i].to,i);
        f[x][1]+=f[e[i].to][0];
        f[x][0]+=max(f[e[i].to][1],f[e[i].to][0]);
    }
}
int main()
{
    memset(st,-1,sizeof st);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a,&b),add(i,b),add(b,i),fun[i]=a;
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        if (vis[i]) continue;
        find_circle(i,-2);
        dfs(x1,-1);
        long long temp=f[x1][0];
        dfs(x2,-1);
        temp=max(temp,f[x2][0]);
        ans+=temp; 
    }
    printf("%lld",ans);
}

