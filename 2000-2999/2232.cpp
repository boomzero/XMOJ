#include <stdio.h>
#include <string.h>
#include <queue>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define fill(x,t) memset(x,t,sizeof(x))
#define min(x,y) ((x)<(y)?(x):(y))
const int INF=0x3f3f3f3f;
const int N=40005;
const int E=320005;
struct edge{int x,y,w,next;}e[E];
std:: queue<int> que;
int dis[N],l[N],c[N];
int rc[105][105];
int ls[N],edCnt=1;
int read() {
    int x=0,v=1; char ch=getchar();
    for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
    for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
    return x*v;
}
void addEdge(int x,int y,int w) {
    e[++edCnt]=(edge){x,y,w,ls[x]}; ls[x]=edCnt;
    e[++edCnt]=(edge){y,x,0,ls[y]}; ls[y]=edCnt;
//  printf("%d %d %d\n",x,y,w);
}
int bfs(int st,int ed) {
    while (!que.empty()) que.pop();
    que.push(st);
    fill(dis,-1);
    dis[st]=1;
    while (!que.empty()) {
        int now=que.front(); que.pop();
        for (int i=ls[now];i;i=e[i].next) {
            if (e[i].w>0&&dis[e[i].y]==-1) {
                dis[e[i].y]=dis[now]+1;
                que.push(e[i].y);
                if (e[i].y==ed) return 1;
            }
        }
    }
    return 0;
}
int find(int now,int ed,int mn) {
    if (now==ed||!mn) return mn;
    int ret=0;
    for (int i=ls[now];i;i=e[i].next) {
        if (e[i].w>0&&dis[now]+1==dis[e[i].y]) {
            int d=find(e[i].y,ed,min(mn-ret,e[i].w));
            e[i].w-=d; e[i^1].w+=d; ret+=d;
            if (ret==mn) break;
        }
    }
    return ret;
}
int dinic(int st,int ed) {
    int ret=0;
    while (bfs(st,ed)) ret+=find(st,ed,INF);
    return ret;
}
int main(void) {
    int n=read(),m=read(),k=read();
    rep(i,1,n) l[i]=read();
    rep(i,1,m) c[i]=read();
    rep(i,1,k) {
        int x=read(),y=read();
        rc[x][y]=1;
    }
    int st=0,ed=n+m+n*m+1;
    rep(i,1,n) addEdge(st,i,l[i]);
    rep(i,1,m) addEdge(i+n,ed,c[i]);
    rep(i,1,n) rep(j,1,m) {
        if (!rc[i][j]) {
            addEdge(i,(i-1)*m+j+n+m,1);
            addEdge((i-1)*m+j+n+m,j+n,1);
        } else {
            l[i]++; c[j]++;
            if (l[i]>m||c[j]>n) {
                puts("JIONG!");
                return 0;
            }
        }
    }
    printf("%d\n",dinic(st,ed));
    return 0;
}

