#include <bits/stdc++.h>
using namespace std;
const int MAXN=510;
struct P {
	int x,y,z;
}p[MAXN];
int n,m,t,k,a[MAXN][MAXN],b[MAXN][MAXN],poi[2][MAXN],dist[30][MAXN*MAXN],vis[MAXN*MAXN],rev[MAXN*MAXN];
int col[MAXN],id[MAXN],dp[MAXN][MAXN];
int hs (int a,int b) {return a*(m+1)+b;}
pair <int,int> revhs (int x) {return make_pair(x/(m+1),x%(m+1));}
bool cmp (P a,P b) {return a.y<b.y;}
int getnx (int x) {
	if (x<=m) {return hs(0,x);}
	if (x<=m+n) {return hs(x-m,m);}
	if (x<=m+n+m) {return hs(n,m+n+m-x);}
	return hs(m+n+m+n-x,0);
}
void dijkstra (int xb,int pt) {
	dist[xb][pt]=0;
	priority_queue < pair<int,int> > q;
	q.push(make_pair(0,pt));
	while (q.size()) {
		pair <int,int> aa=q.top();
		q.pop();
		if (vis[aa.second]) {continue;}
		vis[aa.second]=1;
		pair <int,int> bb=revhs(aa.second);
		if (bb.first!=0&&dist[xb][hs(bb.first-1,bb.second)]>dist[xb][aa.second]+b[bb.first][bb.second]) {
			dist[xb][hs(bb.first-1,bb.second)]=dist[xb][aa.second]+b[bb.first][bb.second];
			q.push(make_pair(-dist[xb][hs(bb.first-1,bb.second)],hs(bb.first-1,bb.second)));
		}
		if (bb.first!=n&&dist[xb][hs(bb.first+1,bb.second)]>dist[xb][aa.second]+b[bb.first+1][bb.second]) {
			dist[xb][hs(bb.first+1,bb.second)]=dist[xb][aa.second]+b[bb.first+1][bb.second];
			q.push(make_pair(-dist[xb][hs(bb.first+1,bb.second)],hs(bb.first+1,bb.second)));
		}
		if (bb.second!=0&&dist[xb][hs(bb.first,bb.second-1)]>dist[xb][aa.second]+a[bb.first][bb.second]) {
			dist[xb][hs(bb.first,bb.second-1)]=dist[xb][aa.second]+a[bb.first][bb.second];
			q.push(make_pair(-dist[xb][hs(bb.first,bb.second-1)],hs(bb.first,bb.second-1)));
		}
		if (bb.second!=m&&dist[xb][hs(bb.first,bb.second+1)]>dist[xb][aa.second]+a[bb.first][bb.second+1]) {
			dist[xb][hs(bb.first,bb.second+1)]=dist[xb][aa.second]+a[bb.first][bb.second+1];
			q.push(make_pair(-dist[xb][hs(bb.first,bb.second+1)],hs(bb.first,bb.second+1)));
		}
	}
	return;
}
int main () {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for (int i=1;i<=n-1;i++) {
		for (int j=1;j<=m;j++) {scanf("%d",&a[i][j]);}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m-1;j++) {scanf("%d",&b[i][j]);}
	}
	for (int i=1;i<=t;i++) {
		for (int i=0;i<=max(n,m);i++) {a[0][i]=a[n][i]=b[i][0]=b[i][m]=0;}
		scanf("%d",&k);
		for (int j=1;j<=k;j++) {scanf("%d%d%d",&p[j].x,&p[j].y,&p[j].z);}
		sort(p+1,p+k+1,cmp);
		int cnt=0,las=0,nw=0;
		for (int j=1;j<=k;j++) {
			if (p[j].y<=m) {a[0][p[j].y]=p[j].x;}
			else if (p[j].y<=m+n) {b[p[j].y-m][m]=p[j].x;}
			else if (p[j].y<=m+n+m) {a[n][m+n+m+1-p[j].y]=p[j].x;}
			else {b[m+n+m+n+1-p[j].y][0]=p[j].x;}
			if (las&&p[j].z!=p[las].z) {
				cnt+=(nw^1);
				poi[nw][cnt]=getnx(p[j].y-1);
				nw^=1;
			}
			if (!las||p[j].z!=p[las].z) {las=j;}
		}
		if (nw==1) {poi[nw][cnt]=hs(0,0);nw^=1;}
		if (cnt==0) {
			printf("0\n");
			continue;
		}
		for (int j=1;j<=cnt;j++) {
			rev[poi[0][j]]=j;
			memset(dist[j],0x3f,sizeof(dist[j]));
			memset(vis,0,sizeof(vis));
			dijkstra(j,poi[0][j]);
		}
		for (int i=1;i<=cnt;i++) {
			col[2*i-1]=col[2*cnt+2*i-1]=0;
			id[2*i-1]=id[2*cnt+2*i-1]=poi[0][i];
			col[2*i]=col[2*cnt+2*i]=1;
			id[2*i]=id[2*cnt+2*i]=poi[1][i];
		}
		for (int i=4*cnt;i>=1;i--) {
			for (int j=i;j<=4*cnt;j++) {
				dp[i][j]=1e9;
				if ((j-i)&1) {
					if (i&1) {dp[i][j]=dp[i+1][j-1]+dist[rev[id[i]]][id[j]];}
					else {dp[i][j]=dp[i+1][j-1]+dist[rev[id[j]]][id[i]];}
					for (int k=i+1;k<j;k+=2) {
						dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]); 
					}
				}
			}
		}
		int ans=1e9;
		for (int i=1;i<=2*cnt;i++) {ans=min(ans,dp[i][i+2*cnt-1]);}
		printf("%d\n",ans);
	}
	return 0;
}
