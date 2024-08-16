#include <bits/stdc++.h>
using namespace std;
int n,m,ans,maxl,minr=1e9;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		maxl=max(maxl,l);
		minr=min(minr,r);
	}
	ans=minr-maxl;
	if(ans<0){
		cout<<0;
		return 0;
	}
	printf("%d",ans+1);
	return 0;
}
