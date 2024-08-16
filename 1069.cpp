#include<iostream>
#include<cstdio>
#include<cstring>
#define N 20
#define MAX 2147483647
using namespace std;
int T,n,x,y,ans,j;
int sum[N];
int qwer(){
	int x,y,z,zz,ans;
	x=y=z=zz=ans=0;
	for (int i=1;i<=14;i++)	{
		if (sum[i]==1) x++;
	 	if (sum[i]==2) y++;
	 	if (sum[i]==3) z++;
	 	if (sum[i]==4) zz++;
	}
	while ((y/2)&&(zz)){
		ans++;
		y-=2;
		zz--;
	}
	while ((x/2)&&(zz)){
		ans++;
		x-=2;
		zz--;
	}
	while (y&&z){
		ans++;
		y--;
		z--;
	}
	while (x&&z){
		ans++;
		x--;
		z--;
	}
	ans+=x+y+z+zz;
	return ans;
}
void dfs(int x){
	if (x>=ans) return;
	int bz=0;
	for (int i=1;i<=14;i++) 
		if (sum[i]){
			bz=1;
			break;	
		} 
	if (!bz){
		ans=min(ans,x);
		return;	
	}
	int t=qwer();
	ans=min(ans,t+x);
	for (int i=1;i<=11;i++)
		for (int j=1;j<=12-i;j++){
			bz=1;
			for (int k=i;k<=i+j;k++)
				if (sum[k]<3) {
					bz=0;
					break;
				}
			if (bz) {
				for (int k=i;k<=i+j;k++) sum[k]-=3;
				dfs(x+1);
				for (int k=i;k<=i+j;k++) sum[k]+=3;
			}
		}
	for (int i=1;i<=10;i++)
		for (int j=2;j<=12-i;j++){
			bz=1;
			for (int k=i;k<=i+j;k++)
				if (sum[k]<2) {
					bz=0;
					break;
				}
				if (bz) {
					for (int k=i;k<=i+j;k++) sum[k]-=2;
					dfs(x+1);
					for (int k=i;k<=i+j;k++) sum[k]+=2;
				}
		}
	for (int i=1;i<=8;i++)
		for (int j=4;j<=12-i;j++){
			bz=1;
			for (int k=i;k<=i+j;k++)
				if (!sum[k]) {
					bz=0;
					break;
				}
				if (bz) {
					for (int k=i;k<=i+j;k++) sum[k]--;
					dfs(x+1);
					for (int k=i;k<=i+j;k++) sum[k]++;
				}
		}
}
int main(){
	scanf("%d%d",&T,&n);
	while (T--){
		j++;
		ans=MAX;
		memset(sum,0,sizeof(sum));
		for (int i=1;i<=n;i++) {
			scanf("%d%d",&x,&y);
			if (!x) sum[14]++;
			else if (x==1) sum[12]++;
			else if (x==2) sum[13]++;
			else sum[x-2]++;
		}
		dfs(0);
		printf("%d\n",ans);
	}
}
