#include <bits/stdc++.h>
using namespace std;
long long m,s,t,run=0,teleport=0;
int main()
{
	cin>>m>>s>>t;
	for(int i=1;i<=t;i++)
	{
		run+=17;
		if(m>=10)
		{
			m-=10;
			teleport+=60;
		}
		else
			m+=4;
		if(teleport>run)
			run=teleport;
		if(run>=s)
		{
			cout<<"Yes"<<"\n"<<i; 
			exit(0);
		}
	}
	if(run<s)
		cout<<"No"<<"\n"<<run;
	return 0;
}
