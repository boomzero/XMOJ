#include <bits/stdc++.h>
using namespace std;
int n,x,five,zero;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x==5)
		{
			five=five+1;
		}
		else
		{
			zero=zero+1;
		}
	}
	if(zero==0)
	{
		cout<<"-1";
	}
	else
	{
		if(five<9)
		{
			cout<<0;
		}
		else
		{
			for(int i=0;i<five/9;i++)
			{
				cout<<"555555555";
			}
			for(int i=0;i<zero;i++)
			{
				cout<<"0";
			}
		}
	}
	return 0;
}
