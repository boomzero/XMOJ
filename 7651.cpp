#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 410000
int n,m,k,ans;
int x[N],y[N];
int a[N],b[N];
vector<int> e[N];

int init_val[N],val[N<<1],rt[N<<1];
void push_up(int rt){
	val[rt]=max(val[rt*2],val[rt*2+1]);
}
void build(int rt,int l,int r){
	if(l==r){
		val[rt]=init_val[l];
		//cout<<"{"<<rt<<" "<<val[rt]<<"}"<<endl;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
} 
void update_one(int rt,int l,int r,int idx,int add){
	if(l==r){
		val[rt]+=add;
		//cout<<"{"<<rt<<" "<<val[rt]<<"}"<<endl;
		return ;
	}
	int mid=(l+r)/2;
	if(idx<=mid) update_one(rt*2,l,mid,idx,add);
	else update_one(rt*2+1,mid+1,r,idx,add);
	push_up(rt);
}
signed main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=k;++i){
		cin>>x[i]>>y[i];
		e[x[i]].push_back(y[i]);
		a[x[i]]++,init_val[y[i]]++;
	}
	build(1,1,m);
	for(int i=1;i<=n;++i){
		if(!a[i]) continue;
		for(auto v:e[i]){
			update_one(1,1,m,v,-1);
			//cout<<"["<<v<<" "<<val[1]<<" "<<val[2]<<" "<<val[3]<<" "<<"]"<<endl;
		}
		//cout<<"<"<<i<<" "<<a[i]<<" "<<val[1]<<">"<<endl;
		ans=max(ans,a[i]+val[1]);
		for(auto v:e[i]){
			update_one(1,1,m,v,1);
		}
	}
	cout<<ans<<endl;
	return 0;
} 
