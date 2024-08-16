# include <bits/stdc++.h>
using namespace std;
int a[200010];
int ans[600010];
int n,kkksc03;
template <typename T> void read(T &a){
	a=0; int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
	do{ a=a*10+ch-'0'; ch=getchar(); } while('0'<=ch&&ch<='9');
	a*=f;
}
inline void write(int from){
	if(!from) putchar('0');
	char f[200];
	int tmp=from>0?from:-from;
	if(from<0) putchar('-');
	int cnt=0;
	while(tmp>0){
		f[cnt++]=tmp%10+'0';
		tmp/=10;
	}
	while(cnt>0) putchar(f[--cnt]);
}
void update_push(int root,int left,int right,int from,int to){
	if(left==right) return ans[root]=max(ans[root],to),void();
	int mid=(left+right)/2;
	if(from<=mid) update_push(root*2,left,mid,from,to);
	else update_push(root*2+1,mid+1,right,from,to);
	ans[root]=max(ans[root*2],ans[root*2+1]);
}
int query_one(int root,int left,int right,int from,int to)
{
	if(left>to || right<from) return -1e9;
	if(from<=left && right<=to) return ans[root];
	int mid=(left+right)/2;
	return max(query_one(root*2,left,mid,from,to),query_one(root*2+1,mid+1,right,from,to));
}
void build_tree(int root,int left,int right){
	ans[root]=-1e9;
	if(left==right) return;
	int mid=(left+right)/2;
	build_tree(root*2,left,mid);build_tree(root*2+1,mid+1,right);
}
int main(){
	freopen("subsequence.in","r",stdin);
	freopen("subsequence.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	build_tree(1,0,n);update_push(1,0,n,0,0);
	for(int i=1;i<n;i++){
		int from=a[i+1];
		int t;
		t=max(max(query_one(1,0,n,1,from-1),query_one(1,0,n,from+1,n))+1,max(query_one(1,0,n,0,0),query_one(1,0,n,from,from)))+kkksc03;
		kkksc03+=(a[i]!=a[i+1]);
		update_push(1,0,n,a[i],t-kkksc03);
	}
	cout<<ans[1]+kkksc03<<endl;
	return 0;
}
