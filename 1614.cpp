#include <bits/stdc++.h>

using namespace std;
const int MAXN=1000;
int nx,ny,vis[MAXN],match[MAXN];
vector<int> g[MAXN];
bool find(int x){
	for(int y:g[x]){
		if(!vis[y]){
			vis[y]=true;
			if(match[y]<0||find(match[y])){
				match[y]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n,m;
	cin>>n>>m;
	nx=n;ny=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int p;
			cin>>p;
			g[i].emplace_back(p);			
		}
	}
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=1;i<=nx;i++){
		memset(vis,0,sizeof(vis));
		if(find(i)) ans++;
	}
	cout<<ans<<endl;
}
