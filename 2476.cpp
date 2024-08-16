#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
template<typename T> void read(T &x)
{
	int w=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')w=ch=='-'?-1:1,ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=w;
}
template <typename T> void write(T x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
template<typename T,typename ...Args>
inline void read(T &x,Args&...args){read(x),read(args...);}
int n,m,len;
int get(int x){return (x-1)/len+1;}
int a[50010],c[50010];
LL ans[50010],L[50010],s;
struct Query{
	int l,r,id;
	bool operator<(const Query &q)const
	{
		int bl=get(l),bq=get(q.l);
		return bl!=bq?bl<bq:bl&1?r<q.r:r>q.r;
	}
}q[50010];
void add(int x){s+=c[a[x]]++;}
void del(int x){s-=--c[a[x]];}
void print(LL a,LL b)
{
	LL d=__gcd(a,b);
	a/=d,b/=d;
	write(a),putchar('/'),write(b),puts("");
}
int main()
{
	int i;
	read(n,m);
	len=ceil(n/sqrt(m));
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=m;i++)
		read(q[i].l,q[i].r),q[i].id=i,
		L[i]=1ll*(q[i].r-q[i].l+1)*(q[i].r-q[i].l)/2;
	
	sort(q+1,q+m+1);
	int l=1,r=0;
	for(i=1;i<=m;i++){
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		while(l>q[i].l)add(--l);
		while(l<q[i].l)del(l++);
		ans[q[i].id]=s;
	}
	for(i=1;i<=m;i++)print(ans[i],L[i]);
}

