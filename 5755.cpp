#include <bits/stdc++.h>

using namespace std;

int s1, s2, s3, tot[90], maxi = 1e9, maxtot;

int main()
{

	//	freopen(".in","r",stdin);

	//	freopen(".out","w",stdout);

	scanf("%d%d%d", &s1, &s2, &s3);

	for (int i = 1; i <= s1; i++)
	{

		for (int j = 1; j <= s2; j++)
		{

			for (int k = 1; k <= s3; k++)
			{

				tot[i + j + k]++;
			}
		}
	}

	for (int i = 3; i < 80; i++)
	{

		if (tot[i] == 0)
			continue;

		//		cout<<tot[i]<<" "<<maxtot<<" "<<i<<" "<<maxi<<endl;

		if (tot[i] > maxtot)
			maxtot = tot[i], maxi = i;

		if (tot[i] == maxtot && i < maxi)
			maxtot = tot[i], maxi = i;
	}

	printf("%d", maxi);

	return 0;
}
