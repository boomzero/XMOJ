#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,len;
char num[5];
ll m,v,p;
struct node{
	int l,r;
	ll mx;
}tree[5000001];
void build(int k,int l,int r){
	tree[k].l=l;
	tree[k].r=r;
	tree[k].mx=-1e16;
	if(l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void move(int dep,int f,ll k){
	if(tree[dep].l==tree[dep].r&&tree[dep].l==f){
		tree[dep].mx=k;
		return;
	}
	int mid=(tree[dep].l+tree[dep].r)>>1;
	if(f<=mid){
		move(dep*2,f,k);
	}
	else{
		move(dep*2+1,f,k);
	}
	tree[dep].mx=max(tree[dep*2].mx,tree[dep*2+1].mx);
}
ll query(int k,int l,int r){
	if(tree[k].l==l&&tree[k].r==r){
		return tree[k].mx;
	}
	int mid=(tree[k].l+tree[k].r)/2;
	if(r<=mid){
		return query(k*2,l,r);
	}
	else if(l>mid){
		return query(k*2+1,l,r);
	}
	return max(query(k*2,l,mid),query(k*2+1,mid+1,r));
}
int main(){
	scanf("%d%lld",&n,&m);
    build(1,1,n);
    for(int i=1;i<=n;i++){
    	scanf("%s%lld",num,&v);
    	if(num[0]=='A'){
    		v=(v+p)%m;
			move(1,++len,v); 
    	}
    	else{
    		p=query(1,len-v+1,len);
    		printf("%lld\n",p);
    	}
    }
	return 0;
}
