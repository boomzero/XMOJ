#include <bits/stdc++.h>
using namespace std;
int n,d,a[2010],ans,i;//n=number of numbers,d=add post,a[i]=the numbers, ans=the answer to be posted out
int m;//m=the tempoary value of the answer
int main(){
    cin>>n>>d;
    for(i=0;i<n;++i){
    	cin>>a[i];
	}
    for(i=0;i<n-1;++i){
        if(a[i]>=a[i+1]){
            m=(a[i]-a[i+1])/d+1;
            ans+=m;
            a[i+1]+=m*d;
        }
    }
    cout<<ans;
    return 0;
}
