#include <cstring>
#include <string>
using namespace std;
string s;
int num[110], f[110][110];
bool check(int l, int r, int len)
{
	for (int i = l; i <= r; ++i)
	{
		if (s[i] != s[(i - l) % len + l])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	char a[100];
	scanf("%s", a);
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		s += a[i];
	}
	memset(f, 0x3f3f3f3f, sizeof(f));
	for (int i = 1; i <= 9; ++i)
	{
		num[i] = 1;
	}
	for (int i = 10; i <= 99; ++i)
	{
		num[i] = 2;
	}
	num[100] = 3;
	for (int i = 0; i < (int)s.size(); i++)
	{
		f[i][i] = 1;
	}
	for (int l = 2; l <= (int)s.size(); l++)
	{
		for (int i = 0; i < (int)s.size(); i++)
		{
			int j = i + l - 1;
			if (j >= (int)s.size())
			{
				break;
			}
			for (int k = i; k < (int)s.size(); k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
			}
			for (int k = i; k < (int)s.size(); k++)
			{
				int len = k - i + 1;
				if (l % len == 0)
				{
					if (check(i, j, len))
					{
						f[i][j] = min(f[i][j], 2 + f[i][k] + num[l / len]);
					}
				}
			}
		}
	}
	printf("%d", f[0][s.size() - 1]);
	return 0;
}
