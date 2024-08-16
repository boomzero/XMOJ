#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dx[8]= {1, 1,-1,-1,2, 2,-2,-2},dy[8]= {2,-2, 2,-2,1,-1, 1,-1};
int n,m,g[20][20],x,y,cnt,vis[20][20],c[20][20],tot;
pii ans[150];
inline bool in(int x,int y) {
	return x>=1&&x<=n&&y>=1&&y<=m;
}
inline void add(int x,int y,int v) {
	for(int i=0; i<8; ++i) {
		int xx=x+dx[i],yy=y+dy[i];
		if (in(xx,yy)&&g[xx][yy]==0&&vis[xx][yy]==0)
			c[xx][yy]+=v;
	}
}
bool dfs(int x,int y,int left,int dep) {
	if(left==0)
		return true;
	vector<pair<int,pii>> nxt;
	for(int i=0;i<8;++i) {
		int xx=x+dx[i],yy=y+dy[i];
		if (in(xx,yy)&&g[xx][yy]==0&&vis[xx][yy]==0) {
			nxt.push_back(make_pair(c[xx][yy],make_pair(xx,yy)));
		}
	}
	sort(nxt.begin(),nxt.end());
	for(auto p:nxt) {
		int xx=p.second.first,yy=p.second.second;
		vis[xx][yy]=1;
		ans[++tot]=make_pair(xx,yy);
		add(xx,yy,-1);
		if (dfs(xx,yy,left-1,dep+1))
			return true;
		add(xx,yy,1);
		--tot;
		vis[xx][yy]=0;
	}
	return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) {
		char s[20];
		scanf("%s",s+1);
		for(int j=1; j<=m; ++j)
			cnt+=(g[i][j]=s[j]-'0');
	}
	scanf("%d%d",&x,&y);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(g[i][j]==0)
				for(int k=0; k<8; ++k)
					if(in(i+dx[k],j+dy[k]))
						c[i][j]+=(g[i+dx[k]][j+dy[k]]==0);
	cnt=n*m-cnt;
	vis[x][y]=1;
	ans[++tot]=make_pair(x,y);
	dfs(x,y,cnt-1,0);
	printf("(%d,%d)",x,y);
	for(int i=2; i<=cnt; ++i)
		printf(">(%d,%d)",ans[i].first,ans[i].second);
	return 0;
}
