#include <bits/stdc++.h>
using namespace std;
const int mx=21;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int n,m,l,k,x,y,cnt=0,ans=-1;
int maze[mx][mx],mem[mx][mx];
struct node{
    int x,y,dep=0;
};
deque <node> qq;
queue <deque<node>> q;
void work()
{
    int nx=0,ny=0,nw=0;
    q.push(qq);
     
    while(!q.empty())
    {
        qq=q.front();q.pop();
         
        node a=qq.front(),b=qq.back();
        qq.pop_back();
        nx=a.x;ny=a.y;nw=a.dep;
         
        if(mem[nx][ny]<=nw || (ans!=-1 && ans<=nw))continue;
        mem[nx][ny]=nw;
        if(nx==1 && ny==1){
            ans=nw;
            return;
        }
        maze[nx][ny]=1;
        for(int i=0;i<=3;++i)
        {
            int _x=nx+dx[i],_y=ny+dy[i];
            if(_x<1 || _x>n || _y<1 || _y>m)continue;
            if(mem[_x][_y]<=nw || maze[_x][_y])continue;
            qq.push_front(node{_x,_y,nw+1});
            q.push(qq);
            qq.pop_front();
        }
        maze[b.x][b.y]=0;
    }
}
int main()
{
    freopen("snake.in","r",stdin);
    freopen("snake.out","w",stdout);
    while(1)
    {
        memset(maze,0,sizeof maze);
        memset(mem,0x3f,sizeof mem);
        n=m=l=k=0;ans=-1;
        while(!q.empty())q.pop();
        while(!qq.empty())qq.pop_front();
        scanf("%d%d%d",&n,&m,&l);
        if(n==m && m==l && l==0)return 0;
        for(int i=1;i<=l;++i){
            scanf("%d%d",&x,&y);
            maze[x][y]=1;
            qq.push_back(node{x,y});
        }
        scanf("%d",&k);
        for(int i=1;i<=k;++i){
            scanf("%d%d",&x,&y);
            maze[x][y]=1;
        }
        work();
        printf("Case %d: %d\n",++cnt,ans);
    }
    return 0;
}
