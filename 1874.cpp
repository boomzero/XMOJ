#include<bits/stdc++.h>
using namespace std;
int t,l,sx,sy,ex,ey;
int dis[1000][1000];
bool vis[1000][1000];
int dx[8]={2,1,-1,-2,-2,-1,1,2},dy[8]={1,2,2,1,-1,-2,-2,-1};
struct P{
	int x,y;
};
int main()
{
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&l);
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	    queue<P> q;
	    memset(dis,0,sizeof(dis));
	    memset(vis,0,sizeof(vis));
	    q.push((P){sx,sy});
	    while (!q.empty()){
	        int x=q.front().x; 
			int y=q.front().y; 
			q.pop(); 
	        if (x==ex&&y==ey)
				break;
	        for(int i=0;i<8;++i){
	            int x2=x+dx[i],y2=y+dy[i];
	            if(x2>=0&&y2>=0&&x2<l&&y2<l){
	            	if(!vis[x2][y2]){
		                q.push((P){x2,y2});
		                dis[x2][y2]=dis[x][y]+1;
		                vis[x2][y2]=1;
	            	}
	            }
	        }
	    }
        printf("%d\n",dis[ex][ey]);
    }
    return 0;
}
