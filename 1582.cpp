#include <bits/stdc++.h>
using namespace std;
int n,mx;
int main(){
	cin>>n;
	for(int a1=0;a1<=n;a1++){
		for(int a2=0;a2<=n;a2++){
			for(int a3=0;a3<=n;a3++){
				if((a1+a2)%2==0&&(a2+a3)%3==0&&(a1+a2+a3)%5==0){
					mx=max(mx,a1+a2+a3);
				}
			}
		}
	}
	cout<<mx;
	return 0; 
}
