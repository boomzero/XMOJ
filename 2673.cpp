#include <bits/stdc++.h>
using namespace std;
char a[60],ans[60];
int t,len;
int main(){
    cin>>a;
    cin>>t;
    len=strlen(a);
    strcpy(ans,a);
    for(int i=1;i<=t;i++){
        for(int j=1;j<len;j++){
            if(a[j]=='G'&&a[j-1]=='B'){
                swap(ans[j],ans[j-1]);
            }
        }
        strcpy(a,ans);
    }
    cout<<ans;
    return 0;
}
