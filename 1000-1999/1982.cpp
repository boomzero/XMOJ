#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
template<class T>
inline bool read(T &n){
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
typedef unsigned long long LL;
const LL base = 31;
struct edge{
    int to,next;
}E[MAXN*2];
char C[MAXN],S[MAXN];
int head[MAXN],si,fa[MAXN],sz[MAXN],que[MAXN],N,vis[MAXN],dist[MAXN],used[MAXN],L;
LL ldist[MAXN],rdist[MAXN],B[MAXN],Pre[MAXN],Suf[MAXN];
void add_edge(int u,int v){
    E[si].to=v;
    E[si].next=head[u];
    head[u]=si++;
}
int get_root(int root){
	int l=0,r=0,res=N+1;fa[root]=0;
    for(que[r++]=root;l<r;l++){
        int now=que[l];
        for(int i=head[now];~i;i=E[i].next){
            int u=E[i].to;
            if(vis[u]||fa[now]==u)continue;
            fa[u]=now;
            que[r++]=u;
        }
    }
    for(;r;r--){
        int now=que[r-1], m=0;
        sz[now]=1;
        for(int i=head[now];~i;i=E[i].next){
            int u=E[i].to;
            if(vis[u]||fa[now]==u)continue;
            sz[now]+=sz[u];
            m=max(m,sz[u]);
        }
        m=max(m,l-sz[now]);
        if(res>m){
            res=m;
            root=now;
        }
    }
    return root;
}
int go(int v,int root){
    int l=0,r=0;
    int ans=0;
   // printf("go(%d,%d):",v,root);
    for(que[r++]=v;l<r;l++){
        int now=que[l];
        if(dist[now]<L&&rdist[now]==Suf[dist[now]]){
            used[dist[now]]++;
        }
       // printf("dist[%d]=%d___%llu__%llu\n",now,dist[now],ldist[now],rdist[now]);
        for(int i=head[now];~i;i=E[i].next){
            int u=E[i].to;
            if(vis[u]||fa[now]==u)continue;
            fa[u]=now;
            dist[u]=dist[now]+1;
            ldist[u]=ldist[now]+C[u-1]*B[dist[u]];
            rdist[u]=rdist[now]+C[u-1]*B[dist[u]-1];
            que[r++]=u;
        }
    }
    for(int i=0;i<r;i++){
        int u=que[i];
        if(dist[u]<L&&ldist[u]==Pre[dist[u]+1])ans+=used[L-dist[u]-1];
    }
    for(int i=0;i<r;i++){
        int u=que[i];
        used[dist[u]]=0;
    }
   // printf("___%d\n",ans);
    return ans;
}
int solve(int root){
    root=get_root(root);fa[root]=0;
  //  printf("root:%d__\n",root);
    dist[root]=0;ldist[root]=C[root-1];rdist[root]=0;vis[root]=true;
    int ans=0;
    ans+=go(root,root);
    for(int i=head[root];~i;i=E[i].next){
        int u=E[i].to;
        if(vis[u])continue;
        ans-=go(u,root);
    }
  //  printf("_____%d\n",ans);
    if(ans>0)return ans;
    for(int i=head[root];~i;i=E[i].next){
        int u=E[i].to;
        if(vis[u])continue;
        ans+=solve(u);
        if(ans>0)return ans;
    }
    return ans;
}
int main(){
    B[0]=1;
    for(int i=1;i<MAXN;i++)B[i]=B[i-1]*base;
    int T;scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        read(N);
        for(int i=0;i<=N;i++){
            vis[i]=used[i]=0;
            head[i]=-1;
        }
        si=0;
        for(int i=1,u,v;i<N;i++){
            read(u);
            read(v);
            add_edge(u,v);
            add_edge(v,u);
        }
        scanf("%s%s",C,S);
        Pre[0]=0;
        Suf[0]=0;
        L=strlen(S);
        for(int i=0;i<L;i++)
        	Pre[i+1]=Pre[i]*base+S[i];
        reverse(S,S+L);
        for(int i=0;i<L;i++)
        	Suf[i+1]=Suf[i]*base+S[i];
        int ans=solve(1);
        printf("Case #%d: ",cas);
      //  printf("___%d\n",ans);
        if(ans){
            puts("Find");
        }
        else puts("Impossible");
    }
    return 0;
}
