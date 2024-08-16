#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y;
    cin>>x>>y;
    if(x!=y)
    	cout<<((x-1)/2)*((y-1)/2);
    else
    	cout<<x*x/4;
    return 0;
}
