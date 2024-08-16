#include <map>
#include <set>
#include <cstdio>
using namespace std;
inline void cmax(int &a,int b){
	if(a<b)
		a=b;
}
int n,b[1010][1010],cid[1010][1010];
int tot,ans1,ans2;
struct G{
	map<int,set<int>> edges;
	map<int,int> connecta;
	map<int,int> id;
	map<int,int> connectb;
	G(){
		edges.clear();
		connecta.clear();
		connectb.clear();
		id.clear();
	}
};
map<int,G> g1;
map<pair<int,int>,G> g2;
namespace Flood{
	int floodfill(G &g,int nid,int id){
		if(g.id.count(nid)>0)
			return 0;
		g.id[nid]=id;
		int a=g.connecta[nid];
		for(int nbrid:g.edges[nid])
			a+=floodfill(g,nbrid,id);
		g.connectb[id]=a;
		return a;
	}
	int two_pointer(G &g){
		int m=0;
		for(auto &p:g.edges)
			cmax(m,floodfill(g,p.first,++tot));
		return m;
	}
}
using namespace Flood;
namespace add_edge{
	void add(G &g,int n1,int n2){
		g.edges[n1].insert(n2);
		g.edges[n2].insert(n1);
		g.connecta[n1]=g.connecta[n2]=1;
	}
	void add2(int i1,int j1,int i2,int j2){
		int b1=b[i1][j1],b2=b[i2][j2];
		int c1=cid[i1][j1],c2=cid[i2][j2];
		if (b1>b2){
			swap(c1,c2);
			swap(b1,b2);
		}
		int r1=g1[b1].id[c1];
		int r2=g1[b2].id[c2];
		pair<int,int> p=make_pair(b1,b2);
		add(g2[p],r1,r2);
		g2[p].connecta[r1]=g1[b1].connectb[r1];
		g2[p].connecta[r2]=g1[b2].connectb[r2];
	}
}
using namespace add_edge;
#define Online_Judge
int main(){
	#ifdef Online_Judge
		freopen("digit.in","r",stdin);
		freopen("digit.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&b[i][j]);
			cid[i][j]=i*n+j;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			add(g1[b[i][j]],cid[i][j],cid[i][j]);
			if(i<n&&b[i+1][j]==b[i][j]){
				add(g1[b[i][j]],cid[i][j],cid[i+1][j]);
			}
			if(j<n&&b[i][j+1]==b[i][j]){
				add(g1[b[i][j]],cid[i][j],cid[i][j+1]);
			}
		}
	}
	for(auto &p:g1){
		cmax(ans1,two_pointer(p.second));
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i<n&&b[i+1][j]!=b[i][j]){
				add2(i,j,i+1,j);
			}
			if(j<n&&b[i][j+1]!=b[i][j]){
				add2(i,j,i,j+1);
			}
		}
	}
	for(auto &p:g2){
		cmax(ans2,two_pointer(p.second));
	}
	printf("%d\n%d",ans1,ans2);
	return 0;
}
