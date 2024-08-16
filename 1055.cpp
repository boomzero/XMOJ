#include<bits/stdc++.h>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define s(x) (x)*(x)
#define dist(x1,y1,x2,y2) (s((x1)-(x2))+s((y1)-(y2)))
struct Edge {
    int u,v;
    double w;
    void set(int _u,int _v,double _w) { u=_u; v=_v; w=_w; }
    bool operator < (const Edge &x) const { return w<x.w; }
} edges[205*205],edges2[205*205];
double dis[205],ans;
int n,x[205],y[205],ec,vis[205];
vector<Edge> g[205];
void SPFA()
{
    queue<int> q;
    for(int i=2;i<=n;i++){
        dis[i]=1e300;
        vis[i]=0;
    }
    dis[1]=0;
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int i=q.front(); q.pop();
        vis[i]=0;
        for(int j=0;j<g[i].size();j++)
            if(dis[g[i][j].v]>dis[i]+g[i][j].w){
                dis[g[i][j].v]=dis[i]+g[i][j].w;
                if(!vis[g[i][j].v]){
                    q.push(g[i][j].v);
                    vis[g[i][j].v]=1;
                }
            }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            edges[ec++].set(i,j,sqrt((double)dist(x[i],y[i],x[j],y[j])));
    sort(edges,edges+ec);
    for (int i=0;i<ec;i++) {
        ans=edges[i].w;
        g[edges[i].u].push_back(edges[i]);
        edges2[i].set(edges[i].v,edges[i].u,edges[i].w);
        g[edges[i].v].push_back(edges2[i]);
        SPFA();
        if (dis[2]<1e300) break;
    }
    printf("%.3lf\n",ans);
    return 0;
}
