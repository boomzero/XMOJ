# include <bits/stdc++.h>
# define gc() (iS==iT && (iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),iS==iT)?EOF:*iS++)
# define pc(c) ((oT==oS+SIZE && flush()),*oT++=(c))
using namespace std;
const int SIZE=(1<<21)+1,L=840;
char ibuf[SIZE],obuf[SIZE],*iS,*iT,*oS=obuf,*oT=obuf;
char* flush(){fwrite(obuf,1,oT-oS,stdout);return oT=obuf;}
struct Flusher{~Flusher(){flush();}}flusher;
int q,pre[15010][850],nxt[15010][850],f[15010][850],g[15010][850],ans[1000010];
bool E[2][15010][850];
char s[10];
struct Storage_q{
	int time_used,x,y,xx,yy;
}qry[1000010];
struct NodePP{
	int time_used,x,y,id;
	NodePP()=default;
	NodePP(int time_used,int x,int y,int i):time_used(time_used),x(x),y(y),id(i){}
};
using vn=vector<NodePP>;
void chkmax(int &x,const int &y){
	x=max(x,y);
}
void solve(int l,int r,const vn &Q){
	if(l>r || Q.empty()) return;
	int mid=(l+r)/2;
	vn Ql,Qr;
	fill(f[mid],f[mid]+L,0);
	for(int i=mid-1;i>=l;i--)
		for(int j=0;j<L;j++)
			f[i][j]=f[i+1][(j+nxt[i][j])%L]+nxt[i][j];
	for(int i=mid+1;i<=r;i++)
		for(int j=0;j<L;j++)
			f[i][j]=f[i-1][(j+pre[i][j])%L]+pre[i][j];
	fill(g[mid],g[mid]+L,0);
	for(int i=mid-1;i>=l;i--)
		for(int j=0;j<L;j++)
			g[i][j]=g[i+1][j]+pre[i+1][(j+g[i+1][j])%L];
	for(int i=mid+1;i<=r;i++)
		for(int j=0;j<L;j++)
			g[i][j]=g[i-1][j]+nxt[i-1][(j+g[i-1][j])%L];
	for(auto &i:Q)
		if(min(i.x,i.y)<=mid && max(i.x,i.y)>=mid)
			chkmax(ans[i.id],f[i.x][i.time_used]+g[i.y][(i.time_used+f[i.x][i.time_used])%L]);
		else
			(i.x<mid?Ql:Qr).push_back(i);
	solve(l,mid-1,Ql);
	solve(mid+1,r,Qr);
}
void query(int n,bool E[15010][850],bool tp){
	for(int i=1;i<n;i++)
		for(int j=L-1;j>=0;j--)
			if(j<L-1){
				pre[i+1][j]=(E[i][j]?0:pre[i+1][j+1]+1);
				nxt[i][j]=(E[i][j]?0:nxt[i][j+1]+1);
			}
			else{
				pre[i+1][j]=nxt[i][j]=0;
				while(!E[i][(j+pre[i+1][j])%L]) pre[i+1][j]++;
				while(!E[i][(j+nxt[i][j])%L]) nxt[i][j]++;
			}
	vn Q;
	for(int i=1;i<=q;i++){
		int x=(!tp?qry[i].x:qry[i].y),y=(!tp?qry[i].xx:qry[i].yy);
		if(x!=y) Q.emplace_back(qry[i].time_used%L,x,y,i);
	}
	solve(1,n,Q);
}
int read(){
	int x=0;
	char ch=gc();
	for(;ch<'0' || ch>'9';ch=gc());
	for(;ch>='0' && ch<='9';ch=gc()) x=x*10+(ch-'0');
	return x;
}
void readln(char *s){
	char ch=gc();
	for(;ch<'0' || ch>'1';ch=gc());
	for(;ch>='0' && ch<='1';ch=gc()) *s++=ch;
	*s=0;
}
void write(int x){
	if(x>=10) write(x/10);
	pc(x%10+'0');
}
int main(){
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	int n,m;
	n=read()+1;m=read()+1;q=read();
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++){
			readln(s);
			int len=strlen(s);
			for(int k=0;k<L;k+=len)
				for(int l=0;l<len;l++)
					E[0][i][k+l]|=(s[l]=='0'),E[1][j][k+l]|=(s[l]=='1');
		}
	for(int i=1;i<=q;i++){
		qry[i].time_used=read();
		qry[i].x=read()+1;qry[i].y=read()+1;
		qry[i].xx=read()+1;qry[i].yy=read()+1;
	}
	query(n,E[0],0);
	query(m,E[1],1);
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]+qry[i].time_used);
	return 0;
}
