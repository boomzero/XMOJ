#include <bits/stdc++.h>
using namespace std;
int n,r[1000010],l[1000010],cnt[1000010],ans=-1,num[1000010];
int dfs1(int u){
	if(l[u]) dfs1(l[u]);
	if(r[u]) dfs1(r[u]);
	return cnt[u]=cnt[l[u]]+cnt[r[u]]+1;
}
bool dfs2(int lp,int rp){
	if(lp==0&&rp==0) return true;
	if(lp==0||rp==0) return false;
	if(num[lp]!=num[rp]||cnt[lp]!=cnt[rp]) return false;
	return dfs2(l[lp],r[rp])&&dfs2(r[lp],l[rp]);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		if(l[i]<0) l[i]=0;
		if(r[i]<0) r[i]=0;
	}
	dfs1(1);
	for(int i=1;i<=n;i++){
		if(ans<cnt[i]&&dfs2(l[i],r[i]))
			ans=cnt[i];
	}
	cout<<ans;
	return 0;
}
//考察知识点：树哈希
