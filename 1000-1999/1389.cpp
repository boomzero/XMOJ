#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(a) ((a)&-(a))
#define clean(a,b) memset(a,b,sizeof(a))
const int mod = 1e9 + 7;
const int inf=0x3f3f3f3f;
const int maxn = 5e4+10;
int _;
struct node
{
    int l,r,lazy,ls,rs,sum;
}tree[maxn*4];
void build(int l,int r,int now)
{
    tree[now].l=l;
    tree[now].r=r;
    tree[now].lazy=0;
    tree[now].ls=tree[now].rs=tree[now].sum=r+1-l;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(l,mid,now<<1);
    build(mid+1,r,now<<1|1);
}
void push_up(int now)
{
    if(tree[now<<1].sum==(tree[now<<1].r-tree[now<<1].l+1))
    {
        tree[now].ls=(tree[now<<1].r-tree[now<<1].l+1)+tree[now<<1|1].ls;
    }
	else
    {
        tree[now].ls=tree[now<<1].ls;
    }
    if(tree[now<<1|1].sum==(tree[now<<1|1].r-tree[now<<1|1].l+1))
    {
        tree[now].rs=(tree[now<<1|1].r-tree[now<<1|1].l+1)+tree[now<<1].rs;
    }
    else
    {
        tree[now].rs=tree[now<<1|1].rs;
    }
    tree[now].sum=max(tree[now<<1].rs+tree[now<<1|1].ls,max(tree[now<<1].sum,tree[now<<1|1].sum));
}
void push_down(int now)
{
    if(tree[now].lazy==0) return ;
    else if(tree[now].lazy==1)
    {
        tree[now<<1].sum=tree[now<<1].ls=tree[now<<1].rs=0;
        tree[now<<1|1].sum=tree[now<<1|1].ls=tree[now<<1|1].rs=0;
        tree[now<<1].lazy=tree[now<<1|1].lazy=1;
    }
    else if(tree[now].lazy==2)
    {
        tree[now<<1].sum=tree[now<<1].ls=tree[now<<1].rs=tree[now<<1].r-tree[now<<1].l+1;
        tree[now<<1|1].sum=tree[now<<1|1].ls=tree[now<<1|1].rs=tree[now<<1|1].r-tree[now<<1|1].l+1;
        tree[now<<1].lazy=tree[now<<1|1].lazy=2;
    }
    tree[now].lazy=0;
}
void update(int l,int r,int now,int tag)//L R 要修改的区间 tag=1 0->1 tag=2 1->0
{
    if(tree[now].l==l&&tree[now].r==r)
    {
        if(tag==1) tree[now].sum=tree[now].ls=tree[now].rs=0;
        else if(tag==2) tree[now].sum=tree[now].ls=tree[now].rs=r-l+1;
        tree[now].lazy=tag;
        return ;
    }
	push_down(now);
    int mid=(tree[now].l+tree[now].r)>>1;
    if(r<=mid) update(l,r,now<<1,tag);
    else if(mid<l) update(l,r,now<<1|1,tag);
    else
    {
        update(l,mid,now<<1,tag);
        update(mid+1,r,now<<1|1,tag);
    }
    push_up(now);
}
int query(int l,int r,int now,int len){
    if(l==r) return l;
    push_down(now);
    int mid=(l+r)>>1;
    if(tree[now<<1].sum>=len) return query(l,mid,now<<1,len);
    else if(tree[now<<1].rs+tree[now<<1|1].ls>=len) return mid-tree[now<<1].rs+1;
    else return query(mid+1,r,now<<1|1,len);
}
int main()
{
    // freopen("in.in","r",stdin);
     // freopen("out.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,n,1);
    for(int i=1;i<=m;i++)
    {//tag=1 0->1 tag=2 1->0
        int num;
        scanf("%d",&num);
        if(num==1)
        {
            int x;
            scanf("%d",&x);
            if(tree[1].sum>=x)
            {
                int ans=query(1,n,1,x);
                printf("%d\n",ans);
                update(ans,ans+x-1,1,1);
            }
            else
            {
                printf("0\n");
            }
        }
        else if(num==2)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            update(x,x+y-1,1,2);
        }
    }
    return 0;
}
