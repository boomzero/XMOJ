#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1006
using namespace std;
inline char nc(){
    static char buf[100000],*i=buf,*j=buf;
    return i==j&&(j=(i=buf)+fread(buf,1,100000,stdin),i==j)?EOF:*i++;
}
inline int _read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int n,N,m,ans;
bool vis[maxn];
struct data{
    int l,r;
}a[maxn];
struct point{
    int x,p,id;
    bool operator <(const point&b)const{return x<b.x;}
}b[maxn*4];
struct nod{
    int l,r,num,tag;
    void add(){
        tag=1;num=r-l+1;
    }
}tree[maxn*16];
void build(int p,int l,int r){
    tree[p].l=l;tree[p].r=r;
    if(l>=r)return;
    int mid=(l+r)>>1;
    build(p<<1,l,mid);build(p<<1|1,mid+1,r);
}
void pushdown(int p){
    if(!tree[p].tag)return;
    tree[p<<1].add();tree[p<<1|1].add();
}
void update(int p,int l,int r){
    if(tree[p].l>r||tree[p].r<l)return;
    if(tree[p].l>=l&&tree[p].r<=r){
        tree[p].add();return;
    }
    pushdown(p);
    update(p<<1,l,r);update(p<<1|1,l,r);
    tree[p].num=tree[p<<1].num+tree[p<<1|1].num;
}
int query(int p,int l,int r){
    if(tree[p].l>r||tree[p].r<l)return 0;
    if(tree[p].l>=l&&tree[p].r<=r)return tree[p].num;
    pushdown(p);
    return query(p<<1,l,r)+query(p<<1|1,l,r);
}
int main(){
    N=10000000;
    int q=_read();
    while(q--){
    	ans=0;
	    n=_read();
	    memset(vis,1,sizeof(vis));
	    for(int i=1;i<=n;i++){
	        a[i].l=_read(),a[i].r=_read();
	        if(a[i].r>N)a[i].r=N;if(a[i].l>N){vis[i]=0;continue;}m++;
	        b[m].x=a[i].l,b[m].id=i,b[m].p=0;m++;b[m].x=a[i].r,b[m].id=i,b[m].p=1;
	        b[++m].x=a[i].l+1;b[m].p=-1;b[++m].x=a[i].r+1;b[m].p=-1;
	    }
	    sort(b+1,b+1+m);int p=0;b[0].x=-1;
	    for(int i=1;i<=m;i++){
	        if(b[i].x>b[i-1].x)p++;
	        if(b[i].p==-1)continue;
	        if(!b[i].p)a[b[i].id].l=p;
	              else a[b[i].id].r=p;
	    }
	    build(1,1,p);
	    for(int i=n;i>=1;i--)if(vis[i]){
	        ans+=(query(1,a[i].l,a[i].r)<a[i].r-a[i].l+1);
	        update(1,a[i].l,a[i].r);
	    }
	    printf("%d\n",ans);
    }
    return 0;
}
