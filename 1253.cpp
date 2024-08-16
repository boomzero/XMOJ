#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
struct Edge{
	int a,b,w;
	bool operator < (const Edge & t)const{
		return w <t.w;
	}
};
struct Point{
	int x,y;
	int dist(Point t){
		return (x - t.x)*(x - t.x) + (y - t.y)*(y - t.y);
	}
} V[N];
int n,q,v[9],p[N];
vector<Edge> Q[8],Tree,edges;
int find(int x){
	return x == p[x]?x:p[x] = find(p[x]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T -- ) {
		edges.clear();
		Tree.clear();
		scanf("%d%d",&n,&q);
		for(int i = 0; i < q; ++i){
			int c,e[N];
			Q[i].clear();
			scanf("%d%d",&c,&v[i]);
			for(int j = 1; j <= c; ++j){
				scanf("%d",&e[j]);
				for(int k = 1; k < j; ++k){
					if(k == j)continue;
					Q[i].push_back({e[j],e[k],0});
				}
			}
			
		}
		for(int i = 1; i <= n; ++i){
			scanf("%d%d",&V[i].x,&V[i].y);
		}
		for(int i = 1; i <= n ; ++i){
			for(int j = 1; j < i; ++j){
				if(i == j)continue;
				int dist = V[i].dist(V[j]);
				edges.push_back({i,j,dist});
			}
		}
		sort(edges.begin(),edges.end());
		for(int i = 1; i <= n ; ++i)p[i] = i;
		for(int i = 0; i < edges.size(); ++i){
			int a = edges[i].a, b = edges[i].b, w = edges[i].w;
			a = find(a),b = find(b);
			if(a != b){
				p[b] = a;
				Tree.push_back(edges[i]);
			}
			if(Tree.size() == n - 1)break;
		}
		sort(Tree.begin(),Tree.end());
		int res = INT_MAX;
		vector<Edge> ans;
		for(int k = 0; k < 1<<q; ++k){
			for(int i = 1; i <= n ; ++i)p[i] = i;
			vector<Edge> curTree;
			int cost = 0;
			
			for(int i = 0; i < q; ++i){
				if(curTree.size() == n - 1)break;
				if(!(k >> i & 1))continue;
				cost += v[i];
				for(int j = 0; j < Q[i].size(); ++j){
					int a = Q[i][j].a, b = Q[i][j].b;
					a = find(a),b = find(b);
					if(a != b){
						p[b] = a;
						curTree.push_back(Q[i][j]);
					}
				}
			}
			for(int i = 0; i < Tree.size(); ++i){
				if(curTree.size() == n - 1)break;
				int a = Tree[i].a, b = Tree[i].b, w = Tree[i].w;
				int pa = find(a),pb = find(b);
				if(pa != pb){
					p[pb] = pa;
					curTree.push_back(Tree[i]);
					cost += V[a].dist(V[b]);
				}
			}
			res = min(res,cost);
		}
		printf("%d\n",res);
	}
	return 0;
}
