#include <bits/stdc++.h>
using namespace std;
int n,ans,l,r,vis[100010];
string s;
int main(){
	freopen("typing.in","r",stdin);
	freopen("typing.out","w",stdout);
	cin>>s;
	n=s.size();
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			vis[i]=true;
			l++;
		}
		if(s[i]==')'){
			r++;
			if(l<r){
				ans++;
				l++,r--;
			}
		}
	}
	cout<<ans+(l-r)/2;
	return 0;
}
