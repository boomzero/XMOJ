#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 11000
int t,n,num[N],sum[N],ans;
string a;
bool flag;
void init(){
	for(int i=1;i<=1000;++i){
		num[i]=0,sum[i]=0;
	}
	ans=0,flag=false;
}
bool judge(int x,int y,int opt){
	int val[10]={0};
	for(int i=x;i<=y;++i){
		int z=i;
		if(i==14) z=1;
		val[num[z]]+=1;
	}
	if(opt==1){
		return val[2]+val[3]+val[4]<=val[1];
	}	
	if(opt==2){
		//cout<<x<<" "<<y<<" "<<val[1]<<" "<<val[2]<<" "<<val[3]<<" "<<val[4]<<endl;
		if(val[4]*2>val[1]) val[1]=val[1]%2,val[4]=0;
		return val[4]*2+val[3]>=val[1]-1;
	}
}
void dfs(){
	if(judge(1,13,2)){
		flag=true;
		return;
	} 
	for(int l=3;l<=14;++l){
		for(int r=l+4;r<=14;++r){
			
			if(flag) return;
			
			bool ff=false;
			for(int k=l;k<=r;++k){
				if(num[(k-1)%13+1]==0) ff=true;
			}
			if(ff) continue;
			
			for(int k=l;k<=r;++k){
				if(k==14) num[1]-=1;
				else num[k]-=1;
			}
			
			dfs();
			
			for(int k=l;k<=r;++k){
				if(k==14) num[1]+=1;
				else num[k]+=1;
			}
		}
	} 
}
signed main(){
	freopen("landlords.in","r",stdin);
	freopen("landlords.out","w",stdout);
	cin>>t;
	while(t--){
		init();
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a;
			if(a=="10") num[10]+=1;
			else if(a[0]>='1'&&a[0]<='9') num[a[0]-'0']+=1;
			else{
				if(a[0]=='J') num[11]+=1;
				if(a[0]=='Q') num[12]+=1;
				if(a[0]=='K') num[13]+=1;
				if(a[0]=='A') num[1]+=1;
			}
		}
		for(int i=1;i<=13;++i){
			sum[i]+=sum[i-1];
			if(num[i]) sum[i]+=1;
		}
		dfs();
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
