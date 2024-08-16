#include <bits/stdc++.h>
using namespace std;
string s;
int a = 1;
int main()
{
	cin >> s;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] != s[i - 1])
		{
			cout << a << s[i - 1];
			a = 0;
		}
		a++;
	}
	cout << a << s[s.length() - 1];
	return 0;
}
