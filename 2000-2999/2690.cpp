#include <bits/stdc++.h>
using namespace std;
int main()
{
	for(int a=1;a<500;a++)
	{
		for(int b=1;b<500;b++)
			if(a*a+(a+1)*(a+1)==b*b)
			{
				cout<<"("<<a<<","<<b<<")"<<" ";
			}
	}
	return 0;
}
