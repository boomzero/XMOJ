#include <bits/stdc++.h>
using namespace std;
int w,h,n,x,y,ai;
bool a[110][110];
void color(int i){
	if(i==1){
		for(int i=0;i<x;i++)
			for(int j=0;j<h;j++)
				a[i][j]=true;
	}
	if(i==2){
		for(int i=x;i<w;i++)
			for(int j=0;j<h;j++)
				a[i][j]=true;
	}
	if(i==3){
		for(int i=0;i<y;i++)
			for(int j=0;j<w;j++)
				a[j][i]=true;
	}
	if(i==4){
		for(int i=y;i<h;i++)
			for(int j=0;j<w;j++)
				a[j][i]=true;
	}
}
int main(){
	cin>>w>>h>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y>>ai;
		if(ai==1) color(1);
		else if(ai==2) color(2);
		else if(ai==3) color(3);
		else color(4);
	}
	int ans=0;
	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
			if(a[i][j]==false)
				ans++;
	cout<<ans;
	return 0;
}
