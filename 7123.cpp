#include <bits/stdc++.h>
using namespace std;
int n,t,out,tot;
string s;
int main(){
		freopen("type.in","r",stdin);
		freopen("type.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		s.erase();
		scanf("%d",&t);
		cin>>s;
		out+=min(12*t/1000,(int)s.size());
		tot+=s.size();
	}
	printf("%d %d",out,tot-out);
	return 0;
}
