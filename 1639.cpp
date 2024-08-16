#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int a[N],b[N],alen,blen;
char str[N];
int main()
{
	cin>>str;
	alen=strlen(str);
	for(int i=0;i<alen;i++){
		a[alen-i]=str[i]-'0';
	}
	cin>>str;
	blen=strlen(str);
	for(int i=0;i<blen;i++){
		b[blen-i]=str[i]-'0';
	}
	for(int i=1;i<=alen;i++){
		a[i]-=b[i];
	}
	for(int i=1;i<=alen;i++){
		if(a[i]<0){
			a[i+1]--;
			a[i]=10+a[i];
		}
	}
	while(a[alen]==0){
		if(alen==1&&a[1]==0){
			break;
		}
		alen--;
	}
	for(int i=alen;i>0;i--){
			cout<<a[i];
	}
    return 0;
}
