#include <bits/stdc++.h>
using namespace std;
int n,b,d,a[1000000],over,feiliao;
int main()
{
	cin>>n>>b>>d;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>b)
		{
			continue;
		}
		else
		{
			feiliao=feiliao+a[i];
		}
		if(feiliao>d)
		{
			over+=1;
			feiliao=0;
		}
	}
	cout<<over;
}
