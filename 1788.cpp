#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

map<unsigned long long, int> mp;

unsigned long long power[maxn], base = 27, mod = 1 << 31;

int main()
{

	int t;
	cin >> t;

	getchar();

	while (t--)
	{

		string line, op, str, buf;

		cin >> op;

		getchar();

		getline(cin, str);

		int len = str.length();

		unsigned long long s = 0;

		for (int i = 0; i < len; i++)
		{

			s = (s * base + (unsigned long long)(str[i] - '\0')) % mod;
		}

		if (op == "find")
		{

			if (mp[s] == 1)
				printf("yes\n");

			else
				printf("no\n");
		}

		else
		{

			mp[s] = 1;
		}
	}
}
