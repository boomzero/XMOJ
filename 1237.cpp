#include <bits/stdc++.h>

using namespace std;

int n, m, ans, k[5010], s[5010], ans1;

int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{

		cin >> k[i] >> s[i];
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{

			if (s[j] < s[j + 1])
			{

				swap(s[j], s[j + 1]);

				swap(k[j], k[j + 1]);
			}

			else if (s[j] == s[j + 1] && k[j] > k[j + 1])
			{

				swap(k[j], k[j + 1]);
			}
		}
	}

	//	for(int i=0;i<n;i++){

	//		cout<<k[i]<<" "<<s[i]<<endl;

	//	}

	//	cout<<endl;

	int ans2 = floor(m * 1.5);

	ans1 = s[ans2 - 1];

	for (int i = 0; i < n; i++)
	{

		if (s[i] < ans1)
			break;

		ans++;
	}

	cout << ans1 << " " << ans << endl;

	for (int i = 0; i < n; i++)
	{

		if (s[i] < ans1)
			return 0;

		cout << k[i] << " " << s[i] << endl;
	}

	return 0;
}
