#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 55
#define M 405
#define Lim 820005
using namespace std;
int len[N],a[N][M],bz[N];
int i,j,k,m,n,o,p,l,s,t,flag;
int ans[Lim][2],tot;
void read(int &x)
{
	char ch=getchar();x=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
}
void move(int i,int j){
	ans[++tot][0]=i,ans[tot][1]=j,len[j]++,a[j][len[j]]=a[i][len[i]],len[i]--;
}
void dg(int l,int r){
	if (l==r) return;
	int mid=l+r>>1;
	memset(bz,0,sizeof(bz));
	for (int pos1=l;pos1<=mid;pos1++)
		for (int pos2=mid+1;pos2<=r;pos2++)
		{
			int i=pos1,j=pos2;
			if (bz[i]||bz[j])
				continue;
			s=flag=0;
			for (int k=1;k<=m;k++)
				s+=(a[i][k]<=mid)+(a[j][k]<=mid);
			if (s<m) swap(i,j),flag=1;
			s=0;
			for (int k=1;k<=m;k++)
				s+=(!flag?a[i][k]<=mid:a[i][k]>mid);
			for (int k=1;k<=s;k++)
				move(j,n+1);
			for (k=len[i];k>=1;k--)
			{
				k=len[i];
				if ((!flag?a[i][k]<=mid:a[i][k]>mid))
					move(i,j);
				else
					move(i,n+1);
			}
			for (int k=1;k<=s;k++)
				move(j,i);
			for (int k=1;k<=m-s;k++)
				move(n+1,i);
			for (int k=1;k<=m-s;k++)
				move(j,n+1);
			for (int k=1;k<=m-s;k++)
				move(i,j);
			for (k=len[n+1];k>=1;k--)
			{
				k=len[n+1];
				if (len[i]!=m&&((!flag?a[n+1][k]<=mid:a[n+1][k]>mid)||len[j]==m))
					move(n+1,i);
				else move(n+1,j);
			}
			bz[i]=1;
		}
	dg(l,mid),dg(mid+1,r);
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n),read(m);
	for (i=1;i<=n;len[i]=m,i++)
		for (j=1;j<=m;j++)
			read(a[i][j]);
	dg(1,n);
	printf("%d\n",tot);
	for(i=1;i<=tot;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}
