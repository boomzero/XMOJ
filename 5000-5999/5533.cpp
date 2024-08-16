#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    stack<char>p;
    for(int i=0;s[i]!='@';i++)
    {
        if(s[i]=='(')
            p.push(s[i]);
        if(s[i]==')')
        {
            if(!p.empty())
                p.pop();
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    if(p.empty())
		cout<<"YES";
    else
		cout<<"NO";
    return 0;
}
