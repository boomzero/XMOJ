#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
struct data{
	int val,num;
	friend bool operator <(data x,data y){if(x.val==y.val)return x.num<y.num;return x.val<y.val;}
}a[N];
int n,ans=1,cnt,vis[N];
signed main(){
	freopen("bsort.in","r",stdin);
	freopen("bsort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].val),a[i].num=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i<a[i].num)
			cnt++;
		if(vis[i])
			cnt--;
		vis[a[i].num]=true;
		ans=max(ans,cnt);
	}
	printf("%d",ans);
}
