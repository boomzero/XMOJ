#include<bits/stdc++.h>
typedef long long LL;
const int N=1e5+5;
int n;
LL a[N],qk[N],qb[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
int head[N];
void add_edge(int u,int v){
	static int k=1;
	edge[k]=(Edge){v,head[u]},head[u]=k++;
}
int bd[N],cnt[N];
void dfs(int u,int fa){
	for(int i=head[u];i;i=edge[i].nxt)
		if(edge[i].to!=fa){
			int v=edge[i].to;
			dfs(v,u);
			bd[u]=std::min(bd[u],bd[v]-1);
		}
}
inline LL div_ceil(LL x,LL y){
	if(y<0)
		x=-x,y=-y;
	return x<0?x/y:(x+y-1)/y;
}
inline LL div_floor(LL x,LL y){
	if(y<0)
		x=-x,y=-y;
	return x<0?(x-y+1)/y:x/y;
}
inline bool calc(LL k,LL b,LL x,LL m,LL target){
	if(k==0)
		return (m-x+1)*b<target;
	else if(k>0){
		LL y=div_ceil(1-b,k);
		__int128_t ret=0;
		if(m>=y)
			ret+=(m-std::max(x,y)+1)*b+(__int128_t)(m+std::max(x,y))*(m-std::max(x,y)+1)/2*k;
		if(x<y)
			ret+=std::min(m+1,y)-x;
		return ret<target;
	}else{
		LL y=div_floor(1-b,k);
		__int128_t ret=0;
		if(x<=y)
			ret+=(std::min(m,y)-x+1)*b+(__int128_t)(std::min(m,y)+x)*(std::min(m,y)-x+1)/2*k;
		if(m>y)
			ret+=m-std::max(x-1,y);
		return ret<target;
	}
}
bool check(int m){
	// printf("check%d\n",m);
	for(int i=1;i<=n;i++){
		int l=1,r=n+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(calc(qk[i],qb[i],mid,m,a[i]))
				r=mid;
			else l=mid+1;
		}
		bd[i]=l-1;
		// printf("bd[%d]=%d\n",i,bd[i]);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(bd[i]<1)
			return false;
	// for(int i=1;i<=n;i++)
		// printf("bd[%d]=%d\n",i,bd[i]);
	for(int i=1;i<=n;i++)
		cnt[i]=0;
	for(int i=1;i<=n;i++)
		cnt[bd[i]]++;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=cnt[i];
		if(sum>i)
			return false;
	}
	return true;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i],&qb[i],&qk[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	// for(int i=1;i<=n;i++)
		// if(calc(qk[i],qb[i],1,1000000000,a[i])){
			// printf("%lld%lld\n",qk[i],qb[i]);
			// return 0;
		// }
	int l=n,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
