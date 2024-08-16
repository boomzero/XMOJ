#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
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
	alen=max(alen,blen);
	for(int i=1;i<=alen;i++){
		a[i]+=b[i];
	}
	for(int i=0;i<=alen;i++){
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[alen+1]!=0) alen++;
	for(int i=alen;i>0;i--){
		cout<<a[i];
	} 
    return 0;
}
