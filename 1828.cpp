#include<cstdio>
inline int max(const int &a,const int &b)
{return a<b?b:a;}
inline int min(const int &a,const int &b)
{return a<b?a:b;}
inline void getint(int &t){
    register char c;t=0;
    do{c=getchar();}while(c<'0'||c>'9');
    while(c<='9'&&c>='0'){t=t*10+c-'0';c=getchar();}
}
struct Node{
    int l,r;
    int le,re,max;
    int lz;
}nodes[510000*5];
inline void pushdown(int index){
    nodes[index<<1].lz=nodes[(index<<1)+1].lz=nodes[index].lz;
    if(nodes[index].lz==1){
        nodes[index<<1].le=nodes[index<<1].re=nodes[index<<1].max=0;
        nodes[(index<<1)+1].le=nodes[(index<<1)+1].re=nodes[(index<<1)+1].max=0;
    }
    else if(nodes[index].lz==2){
        nodes[index<<1].max=nodes[index<<1].re=nodes[index<<1].le
        =nodes[index<<1].r-nodes[index<<1].l+1;
        nodes[(index<<1)+1].max=nodes[(index<<1)+1].re=nodes[(index<<1)+1].le
        =nodes[(index<<1)+1].r-nodes[(index<<1)+1].l+1;
    }
    nodes[index].lz=0;
}
inline void updata(int u){
    nodes[u].max=max(nodes[u<<1].max,nodes[(u<<1)+1].max);
           nodes[u].max=max(nodes[u].max,nodes[u<<1].re+nodes[(u<<1)+1].le);
    nodes[u].le=nodes[u<<1].le;
    nodes[u].re=nodes[(u<<1)+1].re;
    if(nodes[u<<1].le==nodes[u<<1].r-nodes[u<<1].l+1)
        nodes[u].le+=nodes[(u<<1)+1].le;
    if(nodes[(u<<1)+1].re==nodes[(u<<1)+1].r-nodes[(u<<1)+1].l+1)
        nodes[u].re+=nodes[u<<1].re;
}
void build(int u,int l,int r){
    nodes[u].l=l;
    nodes[u].r=r;
    nodes[u].le=nodes[u].re=nodes[u].max=r-l+1;
    if(l==r)return ;
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build((u<<1)+1,mid+1,r);
}
int l,r,k;
void fill(int u){
    if(nodes[u].r<l||nodes[u].l>r)return ;
    if(nodes[u].lz)
        pushdown(u);
    if(nodes[u].l>=l&&nodes[u].r<=r){
        nodes[u].lz=k;
        if(k==2)nodes[u].le=nodes[u].re=nodes[u].max=nodes[u].r-nodes[u].l+1;
        else nodes[u].le=nodes[u].re=nodes[u].max=0;
        return ;
    }
    fill(u<<1);
    fill((u<<1)+1);
    updata(u);
}
int len;
int query(int u){
    if(nodes[u].l==nodes[u].r)return nodes[u].l;
    if(nodes[u].lz)
        pushdown(u);
    if(nodes[u<<1].max>=len)return query(u<<1);
    else if(nodes[u<<1].re+nodes[(u<<1)+1].le>=len)
        return nodes[u<<1].r-nodes[u<<1].re+1;
    else return query((u<<1)+1);
}
int main(){
	freopen("seating.in", "r", stdin);
	freopen("seating.out", "w", stdout);
    int n,m;
    getint(n),getint(m);
    build(1,1,n);
    int ans=0;
    register char o;
    register int a,b,c;
    for(int i=1;i<=m;i++){
        while((o=getchar())!='L'&&o!='A');
        if(o=='L'){
            getint(a);
            getint(b);
            l=a;
            r=b;
            k=2;
            fill(1);
        }else {
            getint(c);
            if(c>nodes[1].max){ans++;continue;}
            len=c;
            int pos=query(1);
            l=pos;
            r=pos+c-1;
            k=1;
            fill(1);
        }
    }
    printf("%d",ans);
}
