#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 500010
using namespace std;

int T, n, m, a[2 * N], l, r, ll, rr, pos[2 * N];
char ans[2 * N];

bool solve ()
{
	if (!ll) return 0;
	for (int i = 2; i <= n; i++)
	{
		if (a[l] == a[ll - 1] && l < ll - 1)
		{
			l++, ll--;
			pos[ll] = 2 * n - i + 1;
			ans[i] = 'L';
		}
		else if (a[l] == a[rr + 1] && l < rr + 1)
		{
			l++, rr++;
			pos[rr] = 2 * n - i + 1;
			ans[i] = 'L';
		}
		else if (a[r] == a[ll - 1] && r > ll - 1)
		{
			r--, ll--;
			pos[ll] = 2 * n - i + 1;
			ans[i] = 'R';
		}
		else if (a[r] == a[rr + 1] && r > rr + 1)
		{
			r--, rr++;
			pos[rr] = 2 * n - i + 1;
			ans[i] = 'R';
		}
		else return 0;
	}
	for (int i = n + 1; i <= 2 * n; i++)
	  if (pos[ll] <= pos[rr]) ll++, ans[i] = 'L';
	  else rr--, ans[i] = 'R';
	return 1;
}
void work ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= 2 * n; i++) scanf ("%d", &a[i]);
	
	memset (pos, 0, sizeof (pos));
	ll = rr = 0;
	for (int i = 2; i <= 2 * n; i++)
	  if (a[i] == a[1])
	  {
	  	ll = rr = i;
	  	pos[i] = 2 * n;
		break;
	  }
	l = 2, r = 2 * n;
	ans[1] = 'L';
	if (solve ())
	{
		for (int i = 1; i <= 2 * n; i++)
		  putchar (ans[i]);
		putchar (10);
		return;
	}
	
	memset (pos, 0, sizeof (pos));
	ll = rr = 0;
	for (int i = 1; i < 2 * n; i++)
	  if (a[i] == a[2 * n])
	  {
	  	ll = rr = i;
	  	pos[i] = 2 * n;
		break;
	  }
	l = 1, r = 2 * n - 1;
	ans[1] = 'R';
	if (solve ())
	{
		for (int i = 1; i <= 2 * n; i++)
		  putchar (ans[i]);
		putchar (10);
		return;
	}
	putchar ('-'), putchar ('1'), putchar (10);
}

int main()
{
freopen("palin.in","r",stdin);
	freopen ("palin.out", "w", stdout);
	scanf ("%d", &T);
	while (T--)
	  work ();
	return 0;
}

