#include <bits/stdc++.h>
using namespace std;
int p[110],x[110],n,m,t[110];
int time1=0;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>p[i]>>x[i];
	}
	for(int i=0;i<m;i++){
		int tmp=t[p[i]-1];
//		cout<<"tmp:"<<tmp<<endl;
		t[p[i]-1]=x[i];
		for(int j=0;j<n;j++){
			time1+=t[j];
		}
		t[p[i]-1]=tmp;
		cout<<time1<<endl;
		time1=0;
	}
	return 0;
}
