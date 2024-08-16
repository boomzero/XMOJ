#include <bits/stdc++.h>
using namespace std;
const int size = 115;
int len;
char s[size];
int main()
{
	cin >> s;
	len = strlen(s);
	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		if (s[i] != s[len - i - 1])
		{
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (s[i] != 'A' && s[i] != 'H' && s[i] != 'I' && s[i] != 'M' && s[i] != 'O' && s[i] != 'T' && s[i] != 'U' && s[i] != 'V' && s[i] != 'W' && s[i] != 'X' && s[i] != 'Y')
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
