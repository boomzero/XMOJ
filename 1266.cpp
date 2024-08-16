#include <bits/stdc++.h>
using namespace std;
int x,y,h1[20];
int mx=0;
bool output[20];
int main(){
	for(int i=1;i<=7;i++){
		cin>>x>>y;
		if(x+y>8){
			h1[x+y]+=1;
			if(h1[x+y]>1&&output[x+y]==false){
				output[x+y]=true;
				cout<<i<<endl;
			}
			else if(h1[x+y]==1){
				output[x+y]=true;
				cout<<i<<endl;
			}
		}
	}
	return 0;
}
