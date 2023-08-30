#include <bits/stdc++.h>

using namespace std;

int n;

char str;

map<string, int> mp;

map<string, int>::iterator iter;

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> str;

		if (str == '+')
		{

			string name;

			cin >> name;

			mp[name]++;
		}

		else if (str == '-')
		{

			string name;

			cin >> name;

			mp[name] = 0;
		}

		else
		{

			int ans = 0;

			for (iter = mp.begin(); iter != mp.end(); iter++)
			{

				if (iter->second != 0)
				{

					ans++;
				}
			}

			cout << ans << endl;

			for (iter = mp.begin(); iter != mp.end(); iter++)
			{

				if (iter->second != 0)
				{

					cout << iter->first.c_str() << " ";
				}
			}
		}
	}

	return 0;
}
