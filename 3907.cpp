#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
typedef long long ll;
typedef long double ldb;
const int N=200005;
#define eps 1e-6
using namespace std;
ll f[N*5][3],q[N],du[N],len[N],ans[N];
queue<ll> h;
ll i,j,k,m,n,o,p,l,s,t;
struct node{
	ldb x,y;
}a[N],ad,c;
namespace IO{
	void read(ll &x){
		char ch=getchar();x=0;
		while (ch<'0'||ch>'9') ch=getchar();
		while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	}
}
using namespace IO;
namespace Operation{
	void insert(ll x,ll y){
		f[++t][1]=y,f[t][2]=q[x],q[x]=t;
	}
	ldb mod(ldb x,ldb y){
		return fmod(x,y);
	}
	ldb gcd(ldb x,ldb y){
		return (mod(x,y)>eps)?gcd(y,mod(x,y)):y;
	}
	node change(ldb x,ldb y){
		ll gys=gcd(x,y);
		return (node){x/gys,y/gys};
	}
	node operator +(const node &a,const node &b){
		ll gys=gcd(a.y,b.y);
		c.y=a.y/gys*b.y,c.x=c.y/a.y*a.x+c.y/b.y*b.x;
		return c;
	}
}
using namespace Operation;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++){
		read(len[i]);
		for(j=1;j<=len[i];j++)
			read(p),insert(i,p),du[p]++;
		if (!len[i]) ans[++ans[0]]=i;
	}
	for(i=1;i<=n;i++)
		if(!du[i])
			h.push(i),a[i]=(node){1,1};
	else
		a[i]=(node){0,1};
	while(!h.empty()){
		ll st=h.front();h.pop();
		if (!len[st])
			continue;
		ad=change(a[st].x,a[st].y*len[st]);
		for(ll k=q[st];k;k=f[k][2]){
			a[f[k][1]]=a[f[k][1]]+ad;
			du[f[k][1]]--;
			if (!du[f[k][1]]) h.push(f[k][1]);
		}
	}
	for(i=1;i<=ans[0];i++)
		a[ans[i]]=change(a[ans[i]].x,a[ans[i]].y),printf("%.0LF %.0LF\n",a[ans[i]].x,a[ans[i]].y);
	return 0;
}
