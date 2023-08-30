#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	//	freopen(".in","r",stdin);
	//	freopen(".out","w",stdout);
	scanf("%d", &n);
	for (int i = n; i > 0; i--)
	{
		if (i % 2 == 1)
			printf("I hate");
		if (i % 2 == 0)
			printf("I love");
		if (i != 1)
			printf(" that ");
	}
	printf(" it");
	return 0;
}
