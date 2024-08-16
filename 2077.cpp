#include <bits/stdc++.h>
using namespace std;
struct Jail {
	int x,y,stp;
	string l;
};
int n,m,p,k,s,g[12][12][12][12];
string key[12][12];
map<pair<string,pair<int,int>>,bool> vis;
queue<Jail> que;
int dx[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool bfs(string ll) {
	que.push({1,1,0,ll});
	while (!que.empty()) {
		Jail u=que.front();que.pop();
		int xx=u.x,yy=u.y,st=u.stp;
		string v=u.l;
		vis[make_pair(v,make_pair(xx,yy))]=true;
		if (xx==n && yy==m) {
			printf("%d",st);
			return true;
		}
		for (int k=0; k<4; k++) {
			int i=xx+dx[k][0],j=yy+dx[k][1];string vv=v;
			if (i<1 || i>n || j<1 || j>m)continue;
			if (g[xx][yy][i][j]==-1) continue;
			for (int x=0; x<key[i][j].size(); x++)
				vv[key[i][j][x]-'0'] = '1';
			if (vis[make_pair(vv, make_pair(i,j))]==1) continue;
			if (g[xx][yy][i][j]>0)
				if (vv[g[xx][yy][i][j]]=='0') continue;
			que.push({i,j,st+1,vv});
		}
	}
	return false;
}
int main() {
	freopen("cat.in", "r", stdin);
	freopen("cat.out", "w", stdout);
	scanf("%d%d%d%d",&n,&m,&p,&k);
	for (int i=1,x,y,xx,yy,z; i<=k; i++) {
		scanf("%d%d%d%d%d",&x,&y,&xx,&yy,&z);
		if (!z) z=-1;
		g[x][y][xx][yy]=z;
		g[xx][yy][x][y]=z;
	}
	scanf("%d",&s);
	for (int i=1,x,y; i<=s; i++) {
		char z[2];scanf("%d%d%s",&x,&y,z);
		key[x][y]+=z[0];
	}
	string ll="";
	for (int i=0; i<=p; i++)
		ll+='0';
	if (!bfs(ll)) printf("Poor");
	return 0;
}
