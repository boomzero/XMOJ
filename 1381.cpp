#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&-x)
#define N 1100000
int n,m,a[N],w[N],ans;
int head=1,tail=1;
int val[N],sum[N];
void push_up(int rt){
	val[rt]=max(val[rt*2],val[rt*2+1]);
}
void build(int rt,int l,int r){
	if(l==r){
		val[rt]=w[l];
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
}
int query(int rt,int l,int r,int ql,int qr){
	if(ql>r||qr<l) return 0;
	if(ql<=l&&qr>=r) return val[rt];
	int mid=(l+r)/2;
	return max(query(rt*2,l,mid,ql,qr),query(rt*2+1,mid+1,r,ql,qr));
}
namespace IO{
	template <typename T> void read(T &a){
		a=0; int f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
		do{ a=a*10+ch-'0'; ch=getchar(); } while('0'<=ch&&ch<='9');
		a*=f;
	}
	template <typename T> void write(T x){
		if(!x) putchar('0');
		char f[200];
		int tmp=x>0?x:-x;
		if(x<0) putchar('-');
		int cnt=0;
		while(tmp>0){
			f[cnt++]=tmp%10+'0';
			tmp/=10;
		}
		while(cnt>0) putchar(f[--cnt]);
	}
}
using namespace IO;
signed main(){
	read(n),read(m);
	ans=1e11;
	for(int i=1;i<=n;++i){
		read(a[i]),read(w[i]);
	}
	build(1,1,n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	while(tail<=n){
		if(tail<head) tail=head;
		while(sum[tail]-sum[head-1]<m&&tail<=n) tail+=1;
		ans=min(ans,query(1,1,n,head,tail));
		head+=1;
	}
	write(ans);
}
