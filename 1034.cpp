#include <bits/stdc++.h>
using namespace std;
struct package{
	long long num,price;
};

int main(){
	freopen("pencil.in","r",stdin);
	freopen("pencil.out","w",stdout);
	int n;
	cin>>n;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	package pencils[4];
	for(int i=1;i<=3;i++){
		cin>>pencils[i].num>>pencils[i].price;
	}
	long long minMoney=0xfffffff;
	for(int i=1;i<=3;i++){
		int p=0;
		if(pencils[i].num==0) continue;
		while(true){
			p++;
			if((p*pencils[i].num)>=n){
				break;
			}
		}
		long long money=p*pencils[i].price;
		//cout<<"Case "<<i<<": Money: "<<money<<" minMoney: "<<minMoney<<endl;
		if(money<minMoney) minMoney=money;
	}
	cout<<minMoney<<endl;
	return 0;
} 
