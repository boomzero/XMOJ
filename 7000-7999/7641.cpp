#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
inline void write(int x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(int x){write(x);putchar('\n');}
const int MAXN=255;
struct edge{int x,y,c,next;}a[MAXN*MAXN*8],E[MAXN*MAXN*2];int len,last[2*MAXN];
bool cmp(edge n1,edge n2){return n1.c>n2.c;}
void ins(int x,int y){len++;a[len].x=x;a[len].y=y;a[len].next=last[x];last[x]=len;}

int sta[2*MAXN],belong[2*MAXN],low[2*MAXN],dfn[2*MAXN],id,cnt,tp;
bool vis[2*MAXN];
void tarjan(int x)
{
	sta[++tp]=x;vis[x]=true;
	low[x]=dfn[x]=++id;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(!dfn[y])tarjan(y),low[x]=min(low[x],low[y]);
		else if(vis[y])low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		cnt++;int i;
		do
		{
			i=sta[tp--];
			belong[i]=cnt;
			vis[i]=false;
		}while(i!=x);
	}
}

int rt[MAXN];
int findrt(int x){return rt[x]==x?rt[x]:rt[x]=findrt(rt[x]);}
int n,col[MAXN],vi[MAXN],tim;
vector<int> vec[MAXN];
void flu(int x)
{
	vi[x]=tim;
	for(int k=0;k<vec[x].size();k++)
	{
		int y=vec[x][k];
		if(vi[y]!=tim)col[y]=col[x]^1,flu(y);
	}
}
int ans,ln;
bool check(int u1,int u2)
{
	len=0;memset(last,0,sizeof(last));
	//1~n 选0   n+1~2*n 选1
	for(int i=1;i<=ln;i++)
	{
		if(E[i].c>u1)
		{
			ins(E[i].x,E[i].y+n);ins(E[i].x+n,E[i].y);
			ins(E[i].y,E[i].x+n);ins(E[i].y+n,E[i].x);
		}
		else if(E[i].c>u2)
		{
			ins(E[i].x+n,E[i].y);
			ins(E[i].y+n,E[i].x);
		}
		else break;
	}
//	puts("YES");
//	pr2(len);
	memset(low,0,sizeof(low));memset(dfn,0,sizeof(dfn));
	id=cnt=tp=0;memset(vis,false,sizeof(vis));
	for(int i=1;i<=2*n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)if(belong[i]==belong[i+n])return false;
	return true;
}
int ct=0;
void work(int u)
{
//	ct++;
	int l=u,r=ln+1,sum;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(E[u].c,E[mid].c))sum=E[mid].c,l=mid+1;
		else r=mid-1;
	}
	ans=min(ans,E[u].c+sum);
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		ln=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)E[++ln].c=read(),E[ln].x=i,E[ln].y=j;
		sort(E+1,E+1+ln,cmp);
		for(int i=1;i<=n;i++)rt[i]=i;
		memset(vi,0,sizeof(vi));tim=0;
		memset(col,-1,sizeof(col));
		ans=(1<<31-1);E[ln+1].c=0;
		for(int i=1;i<=ln;i++)
		{
			int x=E[i].x,y=E[i].y;
			int p=findrt(x),q=findrt(y);
			if(p!=q)
			{
				if(col[x]==-1)col[x]=0;
				vec[x].push_back(y);vec[y].push_back(x);tim++;
				flu(x);ct++;
				rt[p]=q;
				work(i);
			}
			else
			{
				if(col[x]==col[y]){work(i);break;}
				vec[x].push_back(y);vec[y].push_back(x);
			}
//			pr2(ct);
		}
		ct=0;
		pr2(ans);
		for(int i=1;i<=n;i++)vec[i].clear();
	}
	return 0;
}

