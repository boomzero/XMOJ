#include <bits/stdc++.h>
using namespace std;
long long n,x,sm,bg,ans;
//	n=zheng shu ge shu
//	x=every number
//	sm=nunber of numbers smaller than 0
//	bg=number of numbers bigger than 0
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x>0){ 
            ans+=x-1;
        } 
		else if(x<0){
            ans+=-1-x;
            ++sm;
        }
		else{ 
            ++bg;
    	} 
	}
    if(bg>0){
        ans+=bg;
    } 
    else if(sm%2){
        ans+=2;
	}
    cout<<ans;
    return 0;
}
