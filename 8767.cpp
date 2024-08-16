#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> mp;
int A,rum;
int qpow(int b){
	rum++;
	if(b==1)
		return -2;
	int m=qpow(b/2);
	if(b&1)
		return m*m*-2%1000;
	return m*m%1000;
	assert(rum<1e6);
}
int get(int a){
	rum--;
	assert(rum>-1e6);
	if(mp.count(a))
		return mp[a];
	if(a==1)
		return mp[a]=2;
	if(a&1)
		return mp[a]=(get(a/2)*get(a/2+1)%1000-2*qpow(a/2)+2000)%1000;
	return mp[a]=(get(a/2)*get(a/2)%1000-2*qpow(a/2)+2000)%1000;
}
signed main(){
	freopen("mul.in","r",stdin);
	freopen("mul.out","w",stdout);
	cin>>A;
	if(A==0)
		cout<<1;
	else
	cout<<(get(A)-!(A&1)+1000)%1000;
}
