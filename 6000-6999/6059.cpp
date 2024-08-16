#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct miku
{
    int a,b,c,d;
    int w;
    int id;
}s1[50010],s2[50010];
int v[50010];
int n,m,T;
int flag;
int pos[50010];
bool cmp(miku a,miku b)
{
    if(a.a!=b.a)
    {
        return a.a<b.a;
    }
    return a.c<b.c;
}
void add(int x,int val)
{
    for(int i=x;i<=n;i+=i&-i)
    {
        v[i]=max(v[i],val);
    }
}
int ask(int x)
{
    int res=0;
    for(int i=x;i;i-=i&-i)
    {
        res=max(res,v[i]);
    }
    return res;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        flag=0;
        memset(v,0,sizeof(v));
        memset(pos,0,sizeof(pos));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&s1[i].a,&s1[i].b,&s1[i].c,&s1[i].d);
            if(s1[i].a>s1[i].c)
            {
                swap(s1[i].a,s1[i].c);
            }
            if(s1[i].b>s1[i].d)
            {
                swap(s1[i].b,s1[i].d);
            }
            s1[i].w=s1[i].d-s1[i].b;
            s1[i].id=i;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&s2[i].a,&s2[i].b,&s2[i].c,&s2[i].d);
            if(s2[i].a>s2[i].c)
            {
                swap(s2[i].a,s2[i].c);
            }
            if(s2[i].b>s2[i].d)
            {
                swap(s2[i].b,s2[i].d);
            }
            s2[i].w=s2[i].d-s2[i].b;
            s2[i].id=i;
        }
        sort(s1+1,s1+1+n,cmp);
        sort(s2+1,s2+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            pos[s1[i].id]=i;
        }
        for(int i=n;i>=1;i--)
        {
            if(flag==1)
            {
                break;
            }
            if(ask(pos[s2[i].id])+s2[i].w>m)
            {
                flag=1;
            }
            add(pos[s2[i].id],s2[i].w);
        }
        printf(flag==1?"NIE\n":"TAK\n");
    }
}
