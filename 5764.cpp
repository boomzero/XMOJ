#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n,k,now=0,a[N+5],id[N+5],cnt[1<<25],sum[1<<25];
int z[N*30+5],ans1[N+5],ans2[N+5];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int lb(int i){
	return i&(-i);
}
void solve(int s,int t){
	for(int i=1;i<=min(n,25);i++){
		if((s>>(i-1)&1)==(t>>(i-1)&1)) continue;
		if(s>>(i-1)&1) ans1[++ans1[0]]=i;
		else ans2[++ans2[0]]=i;
	}
}
void print(){
	printf("%d ",ans1[0]);
	for(int i=1;i<=ans1[0];i++) printf("%d ",id[ans1[i]]);
	printf("\n%d ",ans2[0]);
	for(int i=1;i<=ans2[0];i++) printf("%d ",id[ans2[i]]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
        id[i]=i;
	}
	for(int i=0;i<=24;i++)
        cnt[1<<i]=i+1;
	if(n<=25){
		for(int s=1;s<1<<n;s++){
			sum[s]=sum[s^lb(s)]+a[id[cnt[lb(s)]]];
			if(z[sum[s]]){
				solve(z[sum[s]],s);
				print();
				return 0;
			}
			z[sum[s]]=s;
		}
		printf("-1");
		return 0;
	}
	sort(id+1,id+n+1,cmp);
	for(int i=n;i>=26;i--){
		if(now<=0){
			ans1[++ans1[0]]=i;
			now+=a[id[i]];
		}
		else{
			ans2[++ans2[0]]=i;
			now-=a[id[i]];
		}
	}
	for(int s=1;s<1<<25;s++){
		sum[s]=sum[s^lb(s)]+a[id[cnt[lb(s)]]];
		z[sum[s]]=s;
	}
	for(int s=1;s<1<<25;s++){
		int tmp=sum[s]+now;
		if(z[tmp]){
			solve(s,z[tmp]);
			print();
			return 0;
		}
	}
	printf("-1");
	return 0;
}
