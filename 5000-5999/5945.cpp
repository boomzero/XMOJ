#include <bits/stdc++.h>
using namespace std;
int n, a[30], len;
__int128 ans = 1;
int print(__int128 x)
{
	if (x == 0)
		return putchar(48) + putchar(10);
	if (x >= 10)
		print(x / 10);
	return putchar(x % 10 + 48);
}
int main()
{
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
	scanf("%d", &n);
	//	if(true){
	for (int i = 0; i < n; i++)
	{
		ans *= 2;
	}
	print(ans);
	return 0;
	//	}
	//	a[0]=1,len=1;
	//	for(int i=0;i<n;i++){
	//		for(int j=0;j<len;j++){
	//			a[j]*=2;
	//		}
	//		for(int j=0;j<len;j++){
	//			if(a[j]>=10){
	//				a[j+1]++;
	//				a[j]-=10;
	//			}
	//		}
	//		if(a[len+1]!=0) len++;
	//	}
	//	for(int i=len-1;i>=0;i++){
	//		printf("%d",a[i]);
	//	}
	return 0;
}
// 我真的栓Q第一题就是高精度（我用int128写的QwQ）
