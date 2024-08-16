#include<bits/stdc++.h>
typedef long long ll;
ll ans=-0x3f3f3f3f;
using namespace std;
ll s[1000010],q[1000010];
ll n,m,head=0,tot=0;
inline ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;x+=int(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		s[i]=read()+s[i-1];
		if(i-q[head]+1>m+1) head++;
		ans=max(s[i]-s[q[head]],ans);
		while(head<=tot&&s[i]<s[q[tot]]) tot--;
		q[++tot]=i;
	}
	cout<<ans;
	return 0;
}
