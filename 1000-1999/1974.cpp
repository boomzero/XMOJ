#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#define ll long long
#define mp make_pair
using namespace std;
struct Node {
	ll b,k;
} node[100000 + 5]; 
set<pair<ll,ll> > st;
int main (){
	freopen("polyline.in", "r", stdin);
	freopen("polyline.out", "w", stdout);
	ll n,k,b;
	cin>>n;
	for(int i = 1; i<=n; i++) {
		scanf("%lld%lld",&k,&b);
		if(k == 0) continue;
		if(k<0&&b<0) k=-k,b=-b;
		if(b == 0) {
			st.insert(mp(0,0));
			continue;
		}
		if(k<0&&b>0) k=-k,b=-b;
		st.insert(mp(k/__gcd(abs(k),abs(b)),b/__gcd(abs(k),abs(b)))); 
	}
	cout << st.size() << endl;
	return 0 ;
}
