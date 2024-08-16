#include <bits/stdc++.h>
//#include <time.h>
using namespace std;
int n,a[210],ans;
bool pd(){
	int os=0;
	for(int i=0;i<n;i++){
		if(a[i]%2==0) os++;
	}
	if(os==n) return true;
	return false;
}
int main(){
	freopen("div2.in","r",stdin);
	freopen("div2.out","w",stdout);
//	clock_t start,end;
//	start=clock();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(pd()==true){
		for(int i=0;i<n;i++){
			a[i]/=2;
		}
		ans++;
	}
	cout<<ans;
//	end=clock();
//	cout<<"time="<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}

