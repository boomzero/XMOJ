#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000+10;
const int MAXM=100000+10;
int n,m,idx,dfn[MAXN],low[MAXN];
string node[MAXN];
map<string,int> mp;
struct Edge {
	int u,v;
	bool flag;
} e[MAXM];
vector<int> g[MAXN];
void tarjan(int u,int fa)
{
	low[u]=dfn[u]=++idx;
	for(int i=0;i<g[u].size();++i) {
		int v=g[u][i];
		if (!dfn[v]) {
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		} else if (v!=fa)
			low[u]=min(low[u],dfn[v]);
	}
}
int pos(string s)
{
	if (mp.find(s)==mp.end()) {
		mp[s]= ++idx;
		node[idx]=s;
	}
	return mp[s];
}
int main()
{
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i) g[i].clear();
		mp.clear();
		idx=0;
		for(int i=0;i<m;i++) {
			char u1[20],v1[20];
			scanf("%s%s",u1,v1);
			string u=u1,v=v1;
			int x=pos(u),y=pos(v);
			e[i].u=x; e[i].v=y; e[i].flag=false;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		idx=0;
		memset(dfn,0,sizeof(dfn));
		tarjan(1,0);
		bool ok=true;
		for(int i=1;ok&&i<=n;++i)
			if(!dfn[i])
				ok=false;
		if(!ok) printf("0\n");
		else {
			int ans=0;
			for(int i=0;i<m;++i) {
				int u=e[i].u, v=e[i].v;
				if (low[u]>dfn[v]||low[v]>dfn[u]) {
					e[i].flag=true;
					++ans;
				}
			}
			printf("%d\n",ans);
			for(int i=0;i<m;++i)
				if(e[i].flag)
					printf("%s %s\n",node[e[i].u].c_str(),node[e[i].v].c_str());
		}
	}
	return 0;
}
