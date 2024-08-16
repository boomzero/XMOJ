#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void cmax(int &x,int y) { if (x<y) x=y; }
inline void cmin(int &x,int y) { if (x>y) x=y; }
const int MAXN=2010;
const int INF=0x3f3f3f3f;
int n,m,a[MAXN],b[MAXN],ans;
int mnl,mxl,mnr[MAXN],mxr[MAXN];
ll mx=-1;
int main() {
	freopen("lottery.in", "r", stdin);
	freopen("lottery.out", "w", stdout);
	cin>>n>>m;
	for (int i=1;i<=m;++i) {
		for (int x=1;x<=n;++x) cin>>a[x];
		ll tot=0;
		mnl=INF,mxl=0;
		memset(mnr,INF,sizeof(mnr));
		memset(mxr,0,sizeof(mxr));
		for (int x=n-1;x>=1;--x) {
			mnr[x]=mnr[x+1]; cmin(mnr[x],a[x]);
			mxr[x]=mxr[x+1]; cmax(mxr[x],a[x]);
		}
		for (int x=1;x<=n;++x) {
			set<int> M;
			if (x>1) cmin(mnl,a[x-1]),cmax(mxl,a[x-1]);
			for (int y=x+1;y<=n;++y) {
				int sc=0,t;
				if (mnl<INF) {
					if (a[x]<a[y]&&mxl>a[x]) cmax(sc,a[y]),cmax(sc,mxl);
					if (a[x]>a[y]&&mnl<a[x]) cmax(sc,a[x]);
				}
				if (M.size()) {
					if ((t=*M.rbegin())>max(a[x],a[y]))  cmax(sc,t);
					if (*M.begin()<min(a[x],a[y]))  cmax(sc,a[x]),cmax(sc,a[y]);
				}
				if (mnr[y]<INF) {
					if (a[x]>a[y]&&mxr[y]>a[y]) cmax(sc,a[x]),cmax(sc,mxr[y]);
					if (a[x]<a[y]&&mnr[y]<a[y]) cmax(sc,a[y]);
				}
				tot+=sc;
				M.insert(a[y]);
			}
		}
		if (tot>mx) mx=tot,ans=i;
	}
	cout<<ans<<endl;
}
