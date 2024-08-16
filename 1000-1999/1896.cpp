#include<cstdio>
#define maxn 1039
#define MOD 222222227//8217 
using namespace std;
typedef long long ll;
typedef long long Type;
inline Type read(){
	Type sum=0;
	int flag=0;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') c=getchar(),flag=1;
	while('0'<=c&&c<='9'){
		sum=(sum<<1)+(sum<<3)+(c^48);
		sum%=MOD;
		c=getchar();
	}
	if(flag) return -sum;
	return sum;
}
int n,m;
ll a[maxn],ans[maxn];
int cnt;
int check(int x){
	ll res=1;
	ll ans=0;
	for(int i=0;i<=n;i++){
		ans+=res*a[i];
		ans%=MOD;
		res=res*x%MOD;
	}
	if(ans%MOD==0) return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        a[i]=read();
    int cnt=0;
    for(int i=1;i<=m;i++)
        if(check(i)){
        	ans[++cnt]=i;
		}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	    printf("%d\n",ans[i]);
	return 0;
}
 
