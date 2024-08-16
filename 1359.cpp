#include<bits/stdc++.h>
using namespace std;
char a[100010];
int main(){
freopen("odd.in","r",stdin);
freopen("odd.out","w",stdout);
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;i+=2){
		cout<<a[i];
	}
}
