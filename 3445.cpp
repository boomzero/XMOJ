#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f;
int dp[110][110];
int n;
string s;
bool check(int a,int b)
{
    if((s[a]=='['&&s[b]==']')||(s[a]=='('&&s[b]==')'))
		return true;
    return false;
}
int main()
{
    cin>>s;
    n=s.size();
    for(int len=1;len<=n;len++)
    {
        for(int l=0;l+len-1<n;l++)
        {
            int r=l+len-1;
            if(len==1)
                dp[l][r]=1;
            else
            {
                dp[l][r]=INF;
                if(check(l,r))
                    dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
                for(int k=l;k<=r;k++)
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
