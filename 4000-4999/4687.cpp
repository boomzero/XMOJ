#include<bits/stdc++.h>
#define mx 10000+5
using namespace std;
int main(){
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	int n,a[mx],b[mx],g[mx],k[mx];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	}
	int x,y;
	cin>>x>>y;
	int tp=-1;
	for(int j=0;j<n;j++){
		if(x>=a[j]&&y>=b[j]&&x<=a[j]+g[j]&&y<=b[j]+k[j])tp=j+1;
	}
	cout<<tp;
	return 0;
}
