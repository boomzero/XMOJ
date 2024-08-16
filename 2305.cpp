#include<algorithm>
#include<cstdio>
#define mid (L+R>>1)
#define pl tr[p].lp
#define pr tr[p].rp
#define Re register int
#define F(a,b) for(i=a;i<=b;++i)
using namespace std;
const int N=2e5+3;char c;
int x,y,i,n,m,cnt,f[N],id[N],pt[N];
struct QAQ{int g,lp,rp;}tr[N<<5];
inline void in(Re &x){
    x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
inline int build(Re L,Re R,Re x){
    Re p=++cnt;++tr[p].g;
    if(L==R)return p;
    if(x<=mid)pl=build(L,mid,x);
    else pr=build(mid+1,R,x);
    return p;
}
inline int merge(Re p,Re q){
    if(!p)return q;if(!q)return p; 
    tr[p].g+=tr[q].g,p;
    pl=merge(pl,tr[q].lp);
    pr=merge(pr,tr[q].rp);
    return p;
}
inline int ask(Re p,Re L,Re R,Re k){
    if(L==R)return id[R];
    Re tmp=tr[pl].g;
    if(tmp>=k)return ask(pl,L,mid,k);
    else return ask(pr,mid+1,R,k-tmp);
}
inline int find(Re x){if(x!=f[x])f[x]=find(f[x]);return f[x];}
int main(){
    in(n),in(m); 
    F(1,n)in(x),id[x]=i,f[i]=i,pt[i]=build(1,n,x);
    while(m--){ 
    	in(x),in(y),x=find(x),y=find(y);
    	merge(pt[x],pt[y]),f[y]=f[x];
    }
    in(m);
    while(m--){
        scanf(" %c",&c),in(x),in(y),x=find(x);
        if(c=='B')y=find(y),merge(pt[x],pt[y]),f[y]=f[x];
        else{
            if(tr[pt[x]].g<y)printf("-1\n");
            else printf("%d\n",ask(pt[x],1,n,y));
        }
     }
}
