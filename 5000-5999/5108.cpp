#include <bits/stdc++.h>
//#include <time.h>
using namespace std;
int t,n;
int sum(){
	int sum=0,m;
	m=n;
	while(m!=0)
	{
		n=m%10;
		m=m/10;
		sum=sum+n;
	}
	return sum;
}
int main(){
	freopen("lucky.in","r",stdin);
	freopen("lucky.out","w",stdout);
//	clock_t start,end;
//	start=clock();
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		if(n%sum()==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
//	end=clock();
//	cout<<"time="<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}

