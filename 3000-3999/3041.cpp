#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int sum=a+b+c+d;
	if(sum%2!=0){
		cout<<"NO";
	}
	else{
		if(a+b==c+d||a+c==b+d||a+d==c+b||b+c==a+d||b+d==a+c){
			cout<<"YES";
		}
		else if(a==b+c+d||b==a+c+d||c==a+b+d||d==a+b+c){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
	}
	return 0;
}
