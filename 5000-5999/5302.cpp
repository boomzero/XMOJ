#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
const LL INF = 5e9;
struct City{
	int id;
	LL al;
	friend bool operator < (City a,City b)
	{
		return a.al<b.al;
	}
};
int n,m,x0,la,lb,ansid;
int s[N],x[N];
int f[20][N][2];
LL da[20][N][2],db[20][N][2],h[N];
double ans = INF*1.0;
multiset<City> q;
void calc(int S,int X)
{
	int p = S;
	la = 0,lb = 0;
	for(int i=18;i>=0;i--){
		if(la+lb+da[i][p][0]+db[i][p][0]<=X)
		{
			la += da[i][p][0];
			lb += db[i][p][0];
			p = f[i][p][0];
		}
	}
}
void pre()
{
	h[0]=INF,h[n+1]=-INF;
	City st;
	st.id = 0,st.al = INF;
	q.insert(st),q.insert(st);
	st.id = n + 1,st.al = -INF;
	q.insert(st),q.insert(st);
	for(int i=n;i;i--)
	{
		int ga,gb;
		City now;
		now.id = i,now.al = h[i];
		q.insert(now);
		auto p = q.lower_bound(now);
		p--;
		LL lt = (*p).id,lh = (*p).al;
		p++,p++;
		LL ne = (*p).id,nh = (*p).al;
		p--;
		if(abs(nh-h[i])>=abs(h[i]-lh))
		{
			gb = lt;
			p--;p--;
			if(abs(nh-h[i])>=abs(h[i]-(*p).al)) ga = (*p).id;
			else ga = ne;
		}
		else
		{
			gb = ne;
			p++,p++;
			if(abs(h[i]-lh)<=abs((*p).al-h[i])) ga = lt;
			else ga = (*p).id;
		}
		f[0][i][0] = ga,f[0][i][1] = gb;
		da[0][i][0] = abs(h[i] - h[ga]);
		db[0][i][1] = abs(h[i] - h[gb]);
	}
	for(int i=1;i<=18;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<2;k++){
		if(i==1)
		{
			auto anc = f[0][j][k];
			f[1][j][k] = f[0][anc][1-k];
			da[1][j][k] = da[0][j][k] + da[0][anc][1-k];
			db[1][j][k] = db[0][j][k] + db[0][anc][1-k];
		}
		else
		{
			auto anc = f[i-1][j][k];
			f[i][j][k] = f[i-1][anc][k];
			da[i][j][k] = da[i-1][j][k] + da[i-1][anc][k];
			db[i][j][k] = db[i-1][j][k] + db[i-1][anc][k];
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",h+i);
	scanf("%d%d",&x0,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",s+i,x+i);
	pre();
	for(int i=1;i<=n;i++)
	{
		calc(i,x0);
		double nans = (double)la/(double)lb;
		if(nans<ans)
		{
			ans = nans;
			ansid = i;
		}
		else if(nans==ans&&h[ansid]<h[i])
			ansid = i;
	}
	printf("%d\n",ansid);
	for(int i=1;i<=m;i++)
	{
		calc(s[i],x[i]);
		printf("%d %d\n",la,lb);
	}
	return 0;
}
