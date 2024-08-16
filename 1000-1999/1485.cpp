#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 110000
int n,m;
stack<int> sta;
bool in_sta[N];
int dfn[N],low[N];
int in_scc[N];
int scc_cnt,scc_num[N];
int idx;
int in_num[N],out_num[N],x[N],y[N],ans[N],ans_num,ans_sum;
int dep[N],rt[N];
vector<int> scc[N],e[N],s_e[N];
bool vis[N];
void tarjan(int u){
	dfn[u]=low[u]=++idx;
	in_sta[u]=true;
	sta.push(u);
	for(auto v:e[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in_sta[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		++scc_cnt;
		int v;
		do{
			v=sta.top();
			sta.pop();
			in_sta[v]=false;
			scc[scc_cnt].push_back(v);
			in_scc[v]=scc_cnt;
			scc_num[scc_cnt]+=1;
		}
		while(v!=u);
	}
}
void solve(){
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(i);
	}
}
int f[N],sum[N];
void init(int x){
	for(int i=1;i<=x;++i){
		dfn[i]=0,low[i]=0;
		in_scc[i]=0,scc_num[i]=0;
		in_num[i]=0,out_num[i]=0;
		ans[i]=0;
		dep[i]=0;
		scc[i].clear(),e[i].clear(),s_e[i].clear();
	}
	m=0,idx=0,scc_cnt=0,ans_num=0;
}
int dfs(int x){
	int ret=0;
	if(vis[x]) return 0;
	for(auto v:s_e[x]){
		ret+=dfs(v);
	}
	ret+=sum[x];
	return ret;
}
signed main(){
	int t;
	cin>>t;
	for(int case_num=1;case_num<=t;++case_num){
		init(11000);
		cin>>n>>m;
		for(int i=1;i<=m;++i){
			cin>>x[i]>>y[i];
			x[i]+=1,y[i]+=1;
			e[x[i]].push_back(y[i]);
		}
		solve();
		for(int i=1;i<=n+100;++i) sum[i]=scc_num[i];
		for(int i=1;i<=m;++i){
			if(in_scc[x[i]]==in_scc[y[i]]) continue;
			out_num[in_scc[x[i]]]+=1;
			in_num[in_scc[y[i]]]+=1;
			s_e[in_scc[y[i]]].push_back(in_scc[x[i]]);
		}
		for(int i=1,q;i<=scc_cnt;++i){
			if(out_num[i]==0){
				for(int j=1;j<=scc_cnt;++j) vis[j]=false;
				q=dfs(i)-1;
				if(q>ans_sum){
					ans_num=1;
					ans[1]=i,ans_sum=q;
				}
				else if(q==ans_sum){
					ans[++ans_num]=i;
				}
			}
		}
		cout<<"Case "<<case_num<<": "<<ans_sum<<endl;
		for(int i=1;i<=n;++i){
			bool f=false;
			for(int j=1;j<=ans_num;++j){
				if(in_scc[i]==ans[j]) f=true;
			}
			if(f) cout<<i-1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
