#include<bits/stdc++.h>
#define N 500010
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,k;
long long p[N],w[N];
priority_queue<long long> cha;
multiset<long long>s;
multiset<long long>::iterator it;
long long ans;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)
		p[i]=read();
	for(int i=1;i<=n;i++){
		w[i]=read();
		s.insert(w[i]);
	}
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++) {
		it=s.upper_bound(p[i]);
		if(it==s.begin())
			continue ;
		it--;
		ans+=p[i];
		cha.push(p[i]-*it);
		s.erase(it);
		if(!s.size())
			break;
	}
	if(s.size()>k){
		cout<<"NIE";
		return 0;
	}
	for(it=s.begin();it!=s.end();it++) {
		ans+=*it;
	}
	k-=s.size();
	for(int i=1;i<=k;i++) {
		ans-=cha.top();
		cha.pop();
		if(!cha.size())
			break;
	}
	cout<<ans;
	return 0;
}
