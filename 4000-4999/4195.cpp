#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int res=0;
    char c;
    bool zf=0;
    while(((c=getchar())<'0'||c>'9')&&c!= '-');
    if(c=='-')zf=1;
    else res=c-'0';
    while((c=getchar())>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0';
    if(zf)return -res;
    return res;
}
const int maxn=2005;
int cnt;
bool vis[maxn];
vector<int>G[maxn];
void dfs(int x,int p,int fa=-1){
	vis[x]=1;
	++cnt;
	if(!p){
		return;
	}
	for(register int i=0;i<G[x].size();++i){
		int v=G[x][i];
		if(v==fa||vis[v]){
			continue;
		}
		dfs(v,p-1,x);
	}
	return;
}
signed main(){
	int n=read(),k=read();
	for(register int i=1;i<n;++i){
		int x=read(),y=read();
		G[x].push_back(y),
		G[y].push_back(x);
	}
	int ans=1e9;
	if(!(k&1)){
		for(register int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			cnt=0;
			dfs(i,k/2);
			ans=min(ans,n-cnt);
		}
	}
	else{
		for(register int i=1;i<=n;++i){
			for(register int j=0;j<G[i].size();++j){
				int v=G[i][j];
				memset(vis,0,sizeof(vis));
				cnt=0;
				dfs(i,k/2,v),dfs(v,k/2,i);
				ans=min(ans,n-cnt);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
