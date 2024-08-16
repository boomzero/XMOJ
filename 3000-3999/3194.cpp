#include <bits/stdc++.h>
using namespace std;
int n,d,a[110],x,ans=2,i,j;
int main(){
    cin>>n>>d;
//  a[i]=setting
//	n=now hotel
//	d=between
//	x=location
//  i,j=temprary
	for(i=0;i<n;++i){
        cin>>a[i];
    }
    for(i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
	}
	// 	paixu 
	d*=2;
    for(i=1;i<n;++i){
        x=a[i]-a[i-1];
        if(x==d){ 
            ans+=1;
        } 
        else if(x>d){ 
        	ans+=2;
    	} 
    }
    cout<<ans;
    return 0;
}
