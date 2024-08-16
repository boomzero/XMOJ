#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Segment_Tree{
    #define lsc(p) p<<1
    #define rsc(p) p<<1|1
    struct Node{
        #define sum1(p) tree[p].sum1
        #define sum2(p) tree[p].sum2
        #define sum3(p) tree[p].sum3
        #define tg1(p) tree[p].tg1
        #define tg2a(p) tree[p].tg2a
        #define tg2d(p) tree[p].tg2d
        #define tg3(p) tree[p].tg3
        int l,r;
        ll sum1,sum2,sum3;
        ll tg1,tg2a,tg2d,tg3;
        int len(){return r-l+1;}
    }tree[int(2e5+5)<<2];
    inline void update(int p,ll tg1,ll tg2a,ll tg2d,ll tg3){
        sum1(p)+=(ll)tg1*tree[p].len();
        sum2(p)+=(ll)tree[p].len()*tg2a-(ll)tree[p].len()*(tree[p].len()-1)/2*tg2d;
        sum3(p)+=(ll)tg3*tree[p].len();
        tg1(p)+=tg1,tg2a(p)+=tg2a,tg2d(p)+=tg2d,tg3(p)+=tg3;
    }
    inline void push_up(int p){
        sum1(p)=sum1(lsc(p))+sum1(rsc(p));
        sum2(p)=sum2(lsc(p))+sum2(rsc(p));
        sum3(p)=sum3(lsc(p))+sum3(rsc(p));
    }
    inline void push_down(int p){
        if(tg1(p)||tg2a(p)||tg2d(p)||tg3(p)){
            update(lsc(p),tg1(p),tg2a(p)-tree[rsc(p)].len()*tg2d(p),tg2d(p),tg3(p));
            update(rsc(p),tg1(p),tg2a(p),tg2d(p),tg3(p));
            tg1(p)=tg2a(p)=tg2d(p)=tg3(p)=0;
        }
    }
    inline void build(int p,int l,int r){
        tree[p].l=l,tree[p].r=r;
        if(l==r)
            return;
        int mid=(tree[p].l+tree[p].r)>>1;
        build(lsc(p),l,mid),build(rsc(p),mid+1,r);
    }
    inline void modify1(int p,int l,int r,int x){
        if(l<=tree[p].l && tree[p].r<=r){
            update(p,x,0,0,0);
            return;
        }
        push_down(p);
        int mid=(tree[p].l+tree[p].r)>>1;
        if(l<=mid) modify1(lsc(p),l,r,x);
        if(r>mid) modify1(rsc(p),l,r,x);
        push_up(p);
    }
    inline void modify2(int p,int l,int r,int a,int d){
        if(l<=tree[p].l && tree[p].r<=r){update(p,0,a,d,0);return;}
        push_down(p);
        int mid=(tree[p].l+tree[p].r)>>1;
        if(r<=mid) modify2(lsc(p),l,r,a,d);
        else if(l>mid) modify2(rsc(p),l,r,a,d);
        else modify2(lsc(p),l,mid,a-(r-mid)*d,d),modify2(rsc(p),mid+1,r,a,d);
        push_up(p);
    }
    inline void modify3(int p,int l,int r,int x){
        if(l<=tree[p].l && tree[p].r<=r){
            update(p,0,0,0,x);
            return;
        }
        push_down(p);
        int mid=(tree[p].l+tree[p].r)>>1;
        if(l<=mid)
            modify3(lsc(p),l,r,x);
        if(r>mid)
            modify3(rsc(p),l,r,x);
        push_up(p);
    }
    inline ll query(int p,int l,int r,int opt){
        if(l<=tree[p].l && tree[p].r<=r){
            if(opt==1) return sum1(p);
            else if(opt==2) return sum2(p);
            else return sum3(p);
        }
        push_down(p);
        int mid=(tree[p].l+tree[p].r)>>1;
        ll ret=0;
        if(l<=mid) ret+=query(lsc(p),l,r,opt);
        if(r>mid) ret+=query(rsc(p),l,r,opt);
        return ret;
    }
}SGT;
vector<int>G[int (2e5+5)];
int dep[int(2e5+5)],fa[int(2e5+5)],son[int(2e5+5)],siz[int(2e5+5)],topp[int(2e5+5)],dfn[int(2e5+5)],tim;
void dfs1(int x,int father){
    dep[x]=dep[father]+1,fa[x]=father,siz[x]=1;
    if(x==1) dep[x]=0;
    for(auto y:G[x]){
        if(y==father) continue;
        dfs1(y,x),siz[x]+=siz[y];
        if(siz[y]>siz[son[x]]) son[x]=y;
    }
}
void dfs2(int x,int root){
    topp[x]=root,dfn[x]=++tim;
    if(!son[x])
        return;
    dfs2(son[x],root);
    for(auto y:G[x])
        if(y!=fa[x] && y!=son[x])
            dfs2(y,y);
}
void add_chain1(int x,int y,int z){
    while(topp[x]!=topp[y]){
        if(dep[topp[x]]<dep[topp[y]]) swap(x,y);
        SGT.modify1(1,dfn[topp[x]],dfn[x],z),x=fa[topp[x]];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    SGT.modify1(1,dfn[x],dfn[y],z);
}
void add_chain2(int x,int y,int z,int d){
    while(topp[x]!=topp[y]){
        if(dep[topp[x]]<dep[topp[y]]) swap(x,y);
        SGT.modify2(1,dfn[topp[x]],dfn[x],z,d),z-=(dfn[x]-dfn[topp[x]]+1)*d,x=fa[topp[x]];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    SGT.modify2(1,dfn[x],dfn[y],z,d);
}
void add_chain3(int x,int y,int z){
    while(topp[x]!=topp[y]){
        if(dep[topp[x]]<dep[topp[y]])
            swap(x,y);
        SGT.modify3(1,dfn[topp[x]],dfn[x],z),x=fa[topp[x]];
    }
    if(dfn[x]>dfn[y])
        swap(x,y);
    SGT.modify3(1,dfn[x],dfn[y],z);
}
ll query_chain(int x,int y,int opt){
    ll ret=0; 
    while(topp[x]!=topp[y]){
        if(dep[topp[x]]<dep[topp[y]])
            swap(x,y);
        ret+=SGT.query(1,dfn[topp[x]],dfn[x],opt),x=fa[topp[x]];
    }
    if(dfn[x]>dfn[y])
        swap(x,y);
    ret+=SGT.query(1,dfn[x],dfn[y],opt);
    ret-=SGT.query(1,dfn[1],dfn[1],opt);
    return ret;
}
void add(int x){
    add_chain1(1,x,1);
    add_chain2(1,x,dep[x]*2-1,2);
    add_chain3(1,x,dep[x]);
}
void del(int x){
    add_chain1(1,x,-1);
    add_chain2(1,x,-dep[x]*2+1,-2);
    add_chain3(1,x,-dep[x]);
}
int main(){
    int n,k;
    cin>>n>>k;
    ++n;
    int u,v;
    for(int i=1;i<n;++i){
        scanf("%d %d",&u,&v),++u,++v;
        G[u].push_back(v),G[v].push_back(u);
    }
    dfs1(1,0),dfs2(1,1),SGT.build(1,1,n);
    ll s=0,ss=0;
    int cnt=0;
    for(int i=2;i<=n;++i){
        ll ans=(ll)dep[i]*dep[i];
        if(i-k-1>1){
            del(i-k-1);
            --cnt;
            s-=dep[i-k-1];
            ss-=(ll)dep[i-k-1]*dep[i-k-1];
        }
        ans+=(ll)dep[i]*dep[i]*cnt;
        ans+=(ll)dep[i]*2*s;
        ans+=ss;
        ans-=(ll)4*dep[i]*query_chain(1,i,1);
        ans+=(ll)4*query_chain(1,i,2);
        ans-=(ll)4*query_chain(1,i,3);
        add(i),++cnt,s+=dep[i],ss+=(ll)dep[i]*dep[i];
        printf("%lld\n",ans);
    }
    return 0;
}
