#include <bits/stdc++.h>
using namespace std;
int n, a[100010], tmp[100010];
void merge_sort(int s, int e)
{
	if (s >= e)
		return;
	int mid = (s + e) / 2, s1 = s, s2 = mid + 1, t = s;
	merge_sort(s, mid);
	merge_sort(mid + 1, e);
	while (s1 <= mid && s2 <= e)
		if (a[s1] < a[s2])
			tmp[t++] = a[s1++];
		else
			tmp[t++] = a[s2++];
	while (s1 <= mid)
		tmp[t++] = a[s1++];
	while (s2 <= e)
		tmp[t++] = a[s2++];
	for (int i = s; i <= e; i++)
		a[i] = tmp[i];
}
int main()
{
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	merge_sort(0, n - 1);
	for (int i = n - 1; i >= 0; i--)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
