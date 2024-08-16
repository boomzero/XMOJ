#include <bits/stdc++.h>
using namespace std;
int n,m,K,tot,head[55],adj[2005],wei[2005],nxt[2005],dis[2005][55];
bool inq[2005][55];
struct Node{
	int x,lev;
};
void addedge(int u,int v,int w){
    tot++;
	adj[tot]=v,wei[tot]=w;
	nxt[tot]=head[u],head[u]=tot;
}
void spfa(){
    int i,j;
    queue <Node> q;
	while(!q.empty())
		q.pop();
    memset(dis,127,sizeof(dis));
    memset(inq,false,sizeof(inq));
    dis[1][0]=0;
	inq[1][0]=true;
    q.push((Node){1,0});
    while(!q.empty()){
        Node x=q.front();
		q.pop();
		inq[x.x][x.lev]=false;
        int lev=x.lev,u=x.x;
        for(i=head[u];i;i=nxt[i]){
            if(dis[u][lev]+wei[i]<dis[adj[i]][lev]){
                dis[adj[i]][lev]=dis[u][lev]+wei[i];
                if(!inq[adj[i]][lev])
                    q.push((Node){adj[i],lev}),inq[adj[i]][lev]=true;;
            }
            if(lev<K&&dis[u][lev]+(wei[i]>>1)<dis[adj[i]][lev+1]){
                dis[adj[i]][lev+1]=dis[u][lev]+(wei[i]>>1);
                if(!inq[adj[i]][lev+1])
                    q.push((Node){adj[i],lev+1}),inq[adj[i]][lev]=true;
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int i,j,u,v,w,ans=2e9;
    scanf("%d%d%d",&n,&m,&K);
	tot=1;
    for (i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
		addedge(v,u,w);
    }
    spfa();
    for (i=0;i<=K;i++)
        ans=min(ans,dis[n][i]);
    printf("%d",ans);
    return 0;
}
