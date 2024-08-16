#include <bits/stdc++.h>
using namespace std;
int t,n,work[110],read,ans;
int main(int argc, const char * argv[]) {
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>work[i];
    }
    for(int i=0;i<n;i++)
    {
        if(read<t)
        {
            read+=86400-work[i];
            ans+=1;
        }
        else{
            break;
        }
    }
    cout<<ans;
    return 0;
}
