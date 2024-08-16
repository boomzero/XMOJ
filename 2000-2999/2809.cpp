#include<stdio.h>
#include<map>
#define N 200005 
using namespace std;
int n,ans,dep[N],s[N],tot;
struct pr
{
    int a,b;
    void st()
    {
        if (b<a) swap(a,b);
    }
    friend bool operator < (pr a,pr b)
    {
        return a.a==b.a?a.b<b.b:a.a<b.a;
    }
};
map<pr,int> M;
struct edge
{
    int v,n;
}e[N<<1];
void push(int &a,int b)
{
    if (!a)
    {
        a=b;
        return;
    }
    e[++tot]=(edge){b,s[a]},s[a]=tot;
    e[++tot]=(edge){a,s[b]},s[b]=tot;
}
void solve(int k,int f)
{
    int mx=0,pm=0;
    for (int i=s[k];i;i=e[i].n) if (e[i].v!=f)
    {
        solve(e[i].v,k);
        if (dep[e[i].v]>mx) pm=mx,mx=dep[e[i].v];
        else if (dep[e[i].v]>pm) pm=dep[e[i].v];
    }
    ans=max(ans,mx+pm+1);
    dep[k]=mx+1;
}
int main()
{
    scanf("%d",&n);
    for (int i=1,a,b,c;i<n-1;i++)
    {
        pr t;
        scanf("%d%d%d",&a,&b,&c);
        t=(pr){a,b};
        t.st();
        push(M[t],i);
        t=(pr){b,c};
        t.st();
        push(M[t],i);
        t=(pr){c,a};
        t.st();
        push(M[t],i);
    }
    solve(1,0);
    printf("%d\n",ans);
    return 0;
}
