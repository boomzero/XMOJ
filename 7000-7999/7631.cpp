#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,ccc=0,cc=0;
ll a[1000010];
ll sss=0,ss=0;
void changemin(int &x,const int &y){
	x=min(x,y);
}
int change(int x){
	return x?x/2+1:0;
}
int main(){
	freopen("delete.in","r",stdin);
	freopen("delete.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ll maxn=*max_element(a+1,a+n+1);
	if(maxn<0){
		int mn=n;
		for(int i=1;i<=n;i++)
			if(a[i]==maxn)
				changemin(mn,change(i-1)+change(n-i));
		printf("%lld\n%d\n",maxn,mn);
		return 0;
	}
	for(int i=1,j=0;i<=n;i+=2){
		if(a[i]>=0){
			ccc+=(j?(i-j)/2:change(i-1));
			sss+=a[i];j=i;
		}
		if(i+2>n)
			ccc+=change(n-j);
	}
	for(int i=2,j=0;i<=n;i+=2){
		if(a[i]>=0){
			cc+=(j?(i-j)/2:change(i-1));
			ss+=a[i];j=i;
		}
		if(i+2>n)
			cc+=change(n-j);
	}
	if(sss>ss)
		printf("%lld\n%d\n",sss,ccc);
	else if(sss<ss)
		printf("%lld\n%d\n",ss,cc);
	else
		printf("%lld\n%d\n",sss,min(ccc,cc));
	return 0;
}
