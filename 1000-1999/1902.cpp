#include <bits/stdc++.h>
using namespace std;
char s[100010];
int ans;
int main()
{
    cin>>s;
	int len=strlen(s);
    for(int i=0;i<len-1;i++){
        if (s[i]!=s[i+1]){
        	ans++;
        }
    }
    cout<<ans;
    return 0;
}
