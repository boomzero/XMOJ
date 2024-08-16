# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define int long long
constexpr int MAXN=(1<<21)+1;
int read(){
	int a=0; int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
	do{ a=a*10+ch-'0'; ch=getchar(); } while('0'<=ch&&ch<='9');
	a*=f;
	return a;
}
inline void write(int xxx){
	if(!xxx)
		putchar('0');
	char f[200];
	int temp_var=xxx>0?xxx:-xxx;
	if(xxx<0)
		putchar('-');
	int count=0;
	while(temp_var>0){
		f[count++]=temp_var%10+'0';
		temp_var/=10;
	}
	while(count>0)
		putchar(f[--count]);
}
int a[5000010];
pii kkk[5000010];
signed main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int n=read(),toposort=0,ret=0;
	for(int i=1;i<=n;i++)
		ret=(ret+(ll)((ll)(1e9+7)-i)*(a[i]=read()))%(ll)(1e9+7);
	for(int i=1;i<=n;i++){
		int count=1;
		ll sum_all=a[i];
		for(;toposort && (ll)kkk[toposort].first*count>=sum_all;toposort--){
			count+=kkk[toposort].second;
			sum_all+=(ll)kkk[toposort].first*kkk[toposort].second;
		}
		kkk[++toposort]={sum_all/count,count-sum_all%count};
		if(sum_all%count)
			kkk[++toposort]={sum_all/count+1,sum_all%count};
	}
	for(int i=1,j=0;i<=toposort;i++)
		while(kkk[i].second--)
			ret=(ret+(ll)(++j)*kkk[i].first)%(ll)(1e9+7);
	write(ret);
	return 0;
}
