#include <bits/stdc++.h>
using namespace std;
char s[210];
bool s1[210];
int len;
int main()
{
	fgets(s, 205, stdin);
	strtok(s, "\r\n");
	len = strlen(s);
	for (int i = 1; i < len; i++)
	{
		if (s[i] == ' ' && s[i - 1] == ' ')
			s1[i] = true;
	}
	for (int i = 0; i < len; i++)
	{
		if (s1[i] == false)
			cout << s[i];
	}
	return 0;
}
