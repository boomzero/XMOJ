#include <bits/stdc++.h>
using namespace std;
char s[100];
int ans, len;
int main()
{
	freopen("title.in", "r", stdin);
	freopen("title.out", "w", stdout);
	fgets(s, 95, stdin);
	strtok(s, "\r\n");
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
			ans++;
		if ('a' <= s[i] && s[i] <= 'z')
			ans++;
		if ('0' <= s[i] && s[i] <= '9')
			ans++;
	}
	cout << ans;
	return 0;
}
