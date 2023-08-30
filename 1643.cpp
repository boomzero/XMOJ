#include <bits/stdc++.h>
int a[10010], al, b[10010], bl;
char s[10010] = {'0', '0', '0', '0', '0', '0', '0', '0'};
void read(int x[], int &xl)
{
	scanf("%s", s + 8);
	xl = (strlen(s + 8) + 7) / 8;
	for (int len = strlen(s + 1), p = 1; len - 8 * p + 1 > 0; p++)
		sscanf(s + len - 8 * p + 1, "%8d", &x[p]);
}
void print(int x[], int xl)
{
	printf("%d", x[xl]);
	for (int i = xl - 1; i >= 1; --i)
		printf("%08d", x[i]);
	printf("\n");
}
bool iszero(int x[], int xl)
{
	for (int i = 1; i <= xl; ++i)
		if (x[i])
			return false;
	return true;
}
void div2(int x[], int &xl)
{
	for (int i = xl; i >= 1; --i)
		x[i - 1] += x[i] % 2 * 100000000, x[i] /= 2;
	while (xl > 1 && x[xl] == 0)
		--xl;
}
void mul2(int x[], int &xl)
{
	for (int i = 1; i <= xl + 1; ++i)
		x[i] = x[i] * 2 + x[i - 1] / 100000000, x[i - 1] %= 100000000;
	while (x[xl + 1])
		x[xl + 2] = x[xl + 1] / 100000000, x[xl + 1] %= 100000000, xl++;
}
bool small(int x[], int xl, int y[], int yl)
{
	if (xl != yl)
		return xl < yl;
	for (int i = xl; i >= 1; --i)
		if (x[i] != y[i])
			return x[i] < y[i];
	return false;
}
void minus(int x[], int &xl, int y[], int yl)
{
	for (int i = 1; i <= xl; ++i)
	{
		x[i] = x[i] - y[i];
		if (x[i - 1] < 0)
			x[i]--;
		x[i - 1] = (x[i - 1] + 100000000) % 100000000;
	}
	while (xl > 1 && x[xl] == 0)
		xl--;
	yl = yl;
}
void gcd()
{
	int g = 0;
	while (!iszero(a, al) && !iszero(b, bl))
	{
		if ((a[1] & 1) == 0 && (b[1] & 1) == 0)
		{
			g++;
			div2(a, al);
			div2(b, bl);
		}
		else if ((a[1] & 1) == 0)
		{
			div2(a, al);
		}
		else if ((b[1] & 1) == 0)
		{
			div2(b, bl);
		}
		else
		{
			if (small(a, al, b, bl))
				minus(b, bl, a, al);
			else
				minus(a, al, b, bl);
		}
	}
	if (iszero(a, al))
		memcpy(a, b, sizeof(a)), al = bl;
	while (g--)
		mul2(a, al);
}
int main()
{
	read(a, al);
	read(b, bl);
	gcd();
	print(a, al);
	return 0;
}
