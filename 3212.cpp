#include <bits/stdc++.h>
using namespace std;
const int size=110;
char s[size];
int ans,len;
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	len=strlen(s);
	for(int i=0;i<len;i++){
		if(i!=len-1&&s[i+1]==s[i]){
			ans++;
		}
		else{
			i++;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
