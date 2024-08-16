#include <bits/stdc++.h>
using namespace std;
int ans;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
const int MAXN=100010;
int n,m,s,d[MAXN],vis[MAXN];
vector <pii> g[MAXN];
int main(){
	//	freopen(".in","r",stdin);
	//	freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		g[i].push_back(make_pair(1,(i+1)%n));
//		g[(i+1)%n].push_back((make_pair(1,i)));
		g[i].push_back(make_pair(0,(i*10)%n));
//		g[(i*10)%n].push_back((make_pair(0,i)));
	}
	memset(vis,0,sizeof vis);
	memset(d,0x3f,sizeof(d));
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	d[1]=0;
	pq.push(make_pair(0,1));
	while(!pq.empty()){
		pii p=pq.top(); pq.pop();
		int u=p.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].second,w=g[u][i].first;
			if(!vis[v]&&d[u]+w<d[v]){
				d[v]=d[u]+w;
				pq.push(make_pair(d[v],v));
			}
		}
	}
	printf("%d",d[0]+1);
	return 0;
}
