#include <bits/stdc++.h>
using namespace std;
int n, d[30];
double wrong = 1;
int main()
{
	scanf("%d", &n);
	int times = -1;
	for (int i = 1; i <= n; i++)
	{
		double chu = 1;
		for (int j = 1; j <= i; j++)
		{
			chu *= j;
		}
		//		cout<<chu<<endl;
		wrong += times * (1.00 / chu);
		times *= -1;
	}
	//	cout<<wrong<<endl;
	cout << fixed << setprecision(2) << 100 * wrong << "%";
	return 0;
}
