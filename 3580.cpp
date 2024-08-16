#include <bits/stdc++.h>
using namespace std;
int m,n,q,c[510][510],b[510][510],r[510][510];
int main(){
		freopen("e.in","r",stdin);
		freopen("e.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	while(m--){
		int i,j;
		cin>>i>>j;
		r[i][j]++;
	}//input lr
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[i][j]=b[i][j-1]+r[i][j];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			c[i][j]=c[i+1][j]+b[i][j];
		}
	}
	while(q--){
		int i,j;
		cin>>i>>j;
		cout<<c[i][j]<<"\n";
	}
	return 0;
}
