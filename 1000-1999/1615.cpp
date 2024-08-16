#include <bits/stdc++.h>

using namespace std;
const int MAXN=10005;
int nx,ny,vis[MAXN],match[MAXN];
vector<int> g[MAXN];
bool find(int x){
	for(int y:g[x]){
		if(y==-1) continue;
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
int id;
int main(){
	int n;
	while(cin>>n){
		int m,k;
		cin>>m>>k;
		nx=n;ny=m;
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			g[x].emplace_back(y+n);
		}
		int ans=0;
		memset(match,-1,sizeof(match));
		for(int i=1;i<=nx;i++){
			memset(vis,0,sizeof(vis));
			if(find(i)) ans++;
		}
		int ip=0;
		for(int i=1;i<=n+m;i++){
			for(int &j:g[i]){
				int bk=j;
				j=-1;
				int fa=0;
				memset(match,-1,sizeof(match));
				for(int i=1;i<=nx;i++){
					memset(vis,0,sizeof(vis));
					if(find(i)) fa++;
				}
				if(ans!=fa) ip++;
				j=bk;
			}
		}
		
		cout<<"Board "<<++id<<" have "<<ip<<" important blanks for "<<ans<<" chessmen."<<endl;
	}
}
