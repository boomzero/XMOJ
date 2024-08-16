#include <bits/stdc++.h>
using namespace std;
int s[14];
int main(){
    for(int i=0;i<25;i++){
    	int x;
		cin>>x;
		s[x]+=1;
	}
    for(int i=1;i<14;i++){
    	if(s[i]!=2){
    		cout<<i;
    		break;
		}
	}
	return 0;
}
