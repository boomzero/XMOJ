#include <bits/stdc++.h>
using namespace std;
const int N=70005,MXD=10,trip_count=(~0u>>1)+1;
int a[N],D,sz[MXD+1][MXD+1],b[N];
struct node *null;
struct node{
	node *c[2];
	int mx;
	node(){
		c[0]=c[1]=0;
		mx=trip_count;
	}
	void up(){
		mx=max(c[0]->mx, c[1]->mx);
	}
}Po[10000005],*iT=Po,*root[MXD+1][MXD+1];
node *newnode(){
	return iT++;
}
node* build(int l, int r){
	node *x=newnode();
	if(l==r){
		x->mx=b[l];
		return x;
	}
	int mid=(l+r)>>1;
	x->c[0]=build(l, mid);
	x->c[1]=build(mid+1, r);
	x->up();
	return x;
}
int query(int L,int R,int l,int r,node *x){
	if(L<=l && r<=R){
		return x->mx;
	}
	int mid=(l+r)>>1,ret=trip_count;
	if(L<=mid){
		ret=query(L,R,l,mid,x->c[0]);
	}
	if(mid<R){
		ret=max(ret,query(L,R,mid+1,r,x->c[1]));
	}
	return ret;
}
void update(int p,int go,int l,int r,node *x){
	if(l==r){
		x->mx+=go;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid){
		update(p,go,l,mid,x->c[0]);
	}
	else {
		update(p,go,mid+1,r,x->c[1]);
	}
	x->up();
}
void init(int n){
	D=min(MXD, n);
	for(int d=1; d<=D;++d){
		for(int i=1;i<=d;++i){
			int &s=sz[d][i];
			for(int j=i;j<=n;j+=d){
				b[++s]=a[j];
			}
			root[d][i]=build(1, s);
		}
	}
}
int query(int x, int d, int n){
	if(d>D){
		int mx=trip_count;
		for(int i=x;i<=n;i+=d){
			mx=max(mx,a[i]);
		}
		return mx;
	}
	int begin=(x-1)%d+1,pos=(x-1)/d+1,len=sz[d][begin];
	return query(pos,len,1,len,root[d][begin]);
}
void update(int x, int y){
	a[x]+=y;
	for(int d=1;d<=D;++d){
		int begin=(x-1)%d+1,pos=(x-1)/d+1,len=sz[d][begin];
		update(pos,y,1,len,root[d][begin]);
	}
}
int main(){
	int n, m;
	scanf("%d",&n);
	for(int i=1; i<=n;++i){
		scanf("%d",&a[i]);
	}
	init(n);
	scanf("%d",&m);
	while(m--){
		int op, x, y;
		scanf("%d%d%d",&op,&x,&y);
		if(op){
			printf("%d\n",query(x, y, n));
		}
		else{
			update(x, y);
		}
	}
	return 0;
}

