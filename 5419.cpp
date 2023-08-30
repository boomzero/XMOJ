#include <bits/stdc++.h>
using namespace std;
int f[1010][1010][2], a[1010][1010], maxans;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			scanf("%d", &a[i][j]);
			f[i][j][0] = a[i][j], f[i][j][1] = 2 * a[i][j];
		}
	}
	//	for(int i=0;i<n;i++){
	//		int j=i+1;
	//		for(int k=0;k<j;k++){
	////			maxans=max(maxans,max(f[0][0][0],f[0][0][1]));
	//			printf("%d ",a[i][j]);
	//		}
	//		printf("\n");
	//	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j >= 0; j--)
		{
			f[i][j][0] = max(f[i - 1][j - 1][0], f[i - 1][j][0]) + a[i][j];
			f[i][j][1] = max(max(f[i - 1][j][0], f[i - 1][j - 1][0]) + a[i][j] * 2, max(f[i - 1][j][1], f[i - 1][j - 1][1]) + a[i][j]);
		}
	}
	//	for(int i=0;i<n;i++){
	//		int j=i+1;
	//		for(int k=0;k<j;k++){
	////			maxans=max(maxans,max(f[0][0][0],f[0][0][1]));
	//			printf("%d ",&f[i][k][0]);
	//		}
	//		printf("\n");
	//	}
	for (int i = 0; i < n; i++)
	{
		int j = i + 1;
		for (int k = 0; k < j; k++)
		{
			maxans = max(maxans, max(f[i][k][0], f[i][k][1]));
			//			printf("ld %lld ",f[i][k][0],f[i][k][1]);
		}
		//				printf("\n");
	}
	printf("%d", maxans);
	return 0;
}
