#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
int n,m,u,v,w,x,y,z,l,r,minn=INT_MAX,maxx=INT_MIN,k;
int tst;
int a[200010];
char s[200010];
#define endl '\n'
#define rd read
static char buf[1<<18],*paa=buf,*pddd=buf;
static char buf2[1<<18],*pppp=buf2;
#define getchar() paa==pddd&&(pddd=(paa=buf)+fread(buf,1,1<<18,stdin),paa==pddd)?EOF:*paa++
int dp[15][1<<15];
int st[1<<15],cnt,tt[15][1<<15];
const int mod=1e9;
bool bit(int x,int y){return x&(1<<(y-1));}
inline void pc(char ch){
	if(pppp-buf2==1<<18) fwrite(buf2,1,1<<18,stdout),pppp=buf2;
	*pppp++=ch;
}
inline void pcc(){
	fwrite(buf2,1,pppp-buf2,stdout);
	pppp=buf2;
}
inline void read(int &n){
	int w=1;
	register int x(0);register char c(getchar());
	while(c<'0'||c>'9'){if(c=='-') w=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	n=w*x;return;
}
inline void write(int x){
	if(x<0) pc('-'),x=-x;
	static int sta[20];int top=0;
	do{sta[top++]=x%10,x/=10;}while(x);
	while(top) pc(sta[--top]+48);
}
inline void we(int x){
	write(x);
	pc('\n');
}
inline void ws(int x){
	write(x);
	pc(' ');
}
int get(char s[])
{
	char ch='=';
	int cnt=0;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++) s[i]=0;
	while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))) ch=getchar();
	while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')) s[++cnt]=ch,ch=getchar();
	return cnt;
}
void put(char s[])
{
	int len=strlen(s+1);
	for(int i=1;i<=len;i++) pc(s[i]);
}
void get(string &s)
{
	s="";
	char ch='=';
	while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))) ch=getchar();
	while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')) s.push_back(ch),ch=getchar();
	return;
}
void put(string s)
{
	int len=s.size();
	for(int i=0;i<len;i++) pc(s[i]);
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	rd(n);rd(m);
	int a[20][20]={};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) rd(a[i][j]);
	}
	const int mx=(1<<m)-1;
	//cout<<bit(3,1)<<" "<<bit(3,2)<<endl;
	cnt=0;
	for(int i=0;i<=mx;i++){
		bool flag=0;
		for(int k=1;k<m;k++){
			if(flag) break;
			if(bit(i,k)&&bit(i,k+1)) flag=1;
		}
		if(flag) continue;
		st[++cnt]=i;
		//cout<<i<<endl;
		//cout<<i<<" "<<bit(i,1)<<" "<<bit(i,2)<<endl;
	}
	int lcnt=0;
	for(int i=1;i<=cnt;i++) {
		int j=st[i];
		bool fl=0;
		for(int k=1;k<=m;k++) {
			if(fl) break;
			if(a[1][k]==0&&bit(j,k)) fl=1;
		}
		if(fl) continue;
		dp[1][j]=1;
		tt[1][++lcnt]=j;
	}
	for(int i=2;i<=n;i++){
		int tcnt=0;
		for(int jj=1;jj<=cnt;jj++){
			//cout<<i<<" "<<st[jj]<<endl;
			int j=st[jj];
			bool flag=0;
			bool fl=0;
			for(int k=1;k<=m;k++) {
				if(fl) break;
				if(a[i][k]==0&&bit(j,k)) fl=1;
			}
			//cout<<i<<" "<<j<<endl;
			if(fl) continue;
			//cout<<i<<" "<<j<<endl;
			for(int kk=1;kk<=lcnt;kk++){
				int k=tt[i-1][kk];
				bool f=0;
				for(int l=1;l<=m;l++) {
					if(f) break;
					if(bit(k,l)&&bit(j,l)) f=1;
				}
				if(f) continue;
				dp[i][j]+=dp[i-1][k];
				//if(j==0) cout<<k<<endl;
				if(dp[i][j]>=mod) dp[i][j]-=mod;
				flag=1;
			}
			if(flag) tt[i][++tcnt]=j;
		}
		lcnt=tcnt;
	}
	int ans=0;
	for(int j=1;j<=lcnt;j++){
		int i=tt[n][j];
		///cout<<tt[n][0]<<endl;
		ans+=dp[n][i];ans%=mod;
	}
	cout<<ans<<endl;
	pcc();
}
