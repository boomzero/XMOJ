#include <bits/stdc++.h>
using namespace std;
int n,n2=1,i=0;
int main(){
		freopen("double.in","r",stdin);
		freopen("double.out","w",stdout);
	scanf("%d",&n);
	while(n2<n){
		n2*=2;
		i++;
	}
	printf("%d",i);
	return 0;
}
