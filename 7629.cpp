# include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int mod=1e9+7;
int n,cur=0,ans=0,deg[610],col[610];
int p[610],q[610],A[610][610],tA[20][610][610],X[610];
bool vis[610];
void add(int &x,const auto &y){
	x=(x+y)%mod;
}
int power(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void slv(int d,int l,int r){
	int tcur=cur;
	for(int i=l;i<=r;i++)
		copy(A[i],A[i]+n+1,tA[d][i]);
	auto undo=[&](){
		for(int i=cur;i>tcur;i--) 
			vis[q[i]]=0;
		for(int i=l;i<=r;i++)
			move(tA[d][i],tA[d][i]+n+1,A[i]);
		cur=tcur;
	};
	if(l==r){
		p[++cur]=l;
		q[cur]=find(vis+1,vis+n+1,0)-vis;
		fill(A[l],A[l]+n+1,0);
		A[l][l]=1;
		for(int i=1;i<n;i++){
			int &v=A[l][q[i]];
			for(int j=i+1;j<=n;j++)
				add(A[l][q[j]],(ll)(mod-v)*A[p[i]][q[j]]);
			add(A[l][0],(ll)(mod-v)*A[p[i]][0]);
			v=0;
		}
		A[l][0]=(ll)A[l][0]*power(A[l][q[n]],mod-2)%mod;
		for(int i=1;i<=n;i++)
			X[i]=A[p[i]][0];
		if(q[n]==1)
			return add(ans,X[n]),undo();
		for(int i=n-1;i>=0;i--){
			for(int j=i+1;j<=n;j++)
				add(X[i],(ll)(mod-A[p[i]][q[j]])*X[j]);
			if(q[i]==1)
				return add(ans,X[i]),undo();
		}
	}
	int mid=(l+r)/2;
	for(int i=r;i>mid;i--){
		int t=0,tot=0;
		for(int j=1;j<=n;j++)
			if(!vis[j])
				col[++tot]=j;
		for(int j=tot;j>=1 && !t;j--)
			if(A[i][col[j]])
				t=col[j];
		assert(t);
		p[++cur]=i;vis[q[cur]=t]=1;
		int iv=power(A[i][t],mod-2);
		for(int j=0;j<=tot;j++)
			A[i][col[j]]=(ll)A[i][col[j]]*iv%mod;
		for(int j=l;j<i;j++){
			int v=A[j][t];
			for(int k=0;k<=tot;k++)
				add(A[j][col[k]],(ll)(mod-v)*A[i][col[k]]);
		}
	}
	slv(d+1,l,mid);undo();
	for(int i=l;i<=mid;i++){
		int t=0,tot=0;
		for(int j=1;j<=n;j++)
			if(!vis[j])
				col[++tot]=j;
		for(int j=tot;j>=1 && !t;j--)
			if(A[i][col[j]])
				t=col[j];
		assert(t);
		p[++cur]=i;vis[q[cur]=t]=1;
		int iv=power(A[i][t],mod-2);
		for(int j=0;j<=tot;j++)
			if(j!=t)
				A[i][col[j]]=(ll)A[i][col[j]]*iv%mod;
		for(int j=r;j>i;j--){
			int v=A[j][t];
			for(int k=0;k<=tot;k++)
				add(A[j][col[k]],(ll)(mod-v)*A[i][col[k]]);
		}
	}
	slv(d+1,mid+1,r);
	undo();
}
int main(){
	freopen("search.in","r",stdin);
	freopen("search.out","w",stdout);
	int m,u,v,w;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		deg[u]++;deg[v]++;
		add(A[u][v],mod-1);add(A[u][0],w);
		add(A[v][u],mod-1);add(A[v][0],w);
	}
	for(int i=1;i<=n;i++){
		int iv=power(deg[i],mod-2);
		for(int j=0;j<=n;j++) A[i][j]=(ll)A[i][j]*iv%mod;
	}
	for(int i=1;i<=n;i++) A[i][i]=1;
	slv(0,1,n);
	ans=(ll)ans*power(n,mod-2)%mod;
	cout<<ans<<"\n";
	return 0;
}
