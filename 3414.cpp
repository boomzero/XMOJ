#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, x, y, i;
int main()
{
	scanf("%d", &n);
	int r[n + 1] = {0};
	for (i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		r[x]++;
		r[y]++;
	}
	r[1] = r[1] + 1;
	for (i = 1; i <= n; i++)
	{
		// r[i]--;
		printf("%d ", r[i] - 1);
	}
}
