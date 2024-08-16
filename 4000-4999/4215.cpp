#include <bits/stdc++.h>
using namespace std;
#define MAXN 700010*20
int n,rt,tot,lc[MAXN],rc[MAXN],val[MAXN],lazy[MAXN];
int new_node(){
	++tot;
	lc[tot]=rc[tot]=val[tot]=lazy[tot]=0;
	return tot;
}
void push_up(int rt){
	val[rt]=min(val[lc[rt]],val[rc[rt]]);
}
void push_down(int rt,int l,int r){
	if(l==r||lazy[rt]==0) return;
	if(!lc[rt]) lc[rt]=new_node();
	val[lc[rt]]+=lazy[rt];
	lazy[lc[rt]]+=lazy[rt];
	if(!rc[rt]) rc[rt]=new_node();
	val[rc[rt]]+=lazy[rt];
	lazy[rc[rt]]+=lazy[rt];
	lazy[rt]=0;
}
void update(int &rt,int l,int r,int ul,int ur,int add){
	if(ul>r||ur<l) return;
	if(!rt) rt=new_node();
	if(ul<=l&&ur>=r){
		val[rt]+=add;
		lazy[rt]+=add;
		return;
	}
	push_down(rt,l,r);
	int mid=(l+r)/2;
	update(lc[rt],l,mid,ul,ur,add);
	update(rc[rt],mid+1,r,ul,ur,add);
	push_up(rt);
}
int query(int &rt,int l,int r,int ql,int qr){
	if(ql>r||qr<l) return 0x3f3f3f3f;
	if(!rt) rt=new_node();
	if(ql<=l&&qr>=r) return val[rt];
	push_down(rt,l,r);
	int mid=(l+r)/2;
	return min(query(lc[rt],l,mid,ql,qr),query(rc[rt],mid+1,r,ql,qr));
}
int main(){
	int q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<q;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			update(rt,1,n,a,b,v);
		}
		else{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",query(rt,1,n,a,b));
		}
	}
}
