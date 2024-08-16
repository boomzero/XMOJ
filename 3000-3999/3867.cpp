#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define LL long long
#define ULL unsigned long long
#define N 1000010
using namespace std;int n,m,c,p,q,mm,wz;
ULL now,res=1,S,k;
bool flg[65],tp;
struct node{ULL p,q;}a[N];
inline LL read(){
	char c;LL d=1,f=0;
	while(c=getchar(),!isdigit(c)) if(c=='-') d=-1;f=(f<<3)+(f<<1)+c-48;
	while(c=getchar(),isdigit(c)) f=(f<<3)+(f<<1)+c-48;
	return d*f;
}
signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	if(k==64)
		puts("18446744073709551616"),exit(0);
	S=1;
	for(register int i=1;i<=k;i++)
		S<<=1;
	for(register int i=1;i<=n;i++)
		now|=read();
	for(register int i=1;i<=m;i++)
		a[i].p=read(),a[i].q=read();
	for(register int i=1;i<=m;i++)
		if(!((now>>a[i].p)&1))
			flg[a[i].p]=true;
	for(register int i=0;i<k;i++)
		if(flg[i]){
			if(tp)
				S=9223372036854775808ull,tp=0;
			else
				S>>=1;
		}
	printf("%llu",S-n+tp);
}
