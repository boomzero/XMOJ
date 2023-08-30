#include <bits/stdc++.h>

using namespace std;

int n;

char s[10000];

int main()
{

	freopen("cipher.in", "r", stdin);

	freopen("cipher.out", "w", stdout);

	scanf("%s", s);

	for (int i = 0; s[i]; ++i)

		s[i] = (s[i] - 'A' - i - 1 + 2600) % 26 + 'A';

	puts(s);

	return 0;
}
