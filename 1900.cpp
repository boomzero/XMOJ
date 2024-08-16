#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	if(a+b==c) cout<<"Yes";
	else if(a+c==b) cout<<"Yes";
	else if(b+c==a) cout<<"Yes";
	else cout<<"No";
	return 0;
}
