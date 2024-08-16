#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,W;
int w[300],t[300];
long long f[10000];
bool check(int z){
	memset(f,128,sizeof(f));f[0]=0;
	long long tmp=f[W];
	for(int i=1;i<=n;i++){
		for(int j=W;j>=0;j--)if(f[j]!=tmp){
			int jj=j+w[i];jj=min(jj,W);
			f[jj]=max(f[jj],f[j]+t[i]-(long long)w[i]*z);
		}
	}
	return f[W]>=0;
}
int erfen(){
	int l=0,r=1000000;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main(){
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&t[i]);
		t[i]*=1000;
	}
	printf("%d",erfen());
	return 0;
}
