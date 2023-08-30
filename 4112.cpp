#include <bits/stdc++.h>

using namespace std;

string s;

int pos[100], pos2[100]; // A=65, Z=90

int len, ans;

int main()
{

	freopen("cross.in", "r", stdin);

	freopen("cross.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	len = s.size();

	for (int i = 0; i < len; i++)
	{

		for (int j = 0; j < len; j++)
		{

			if (i == j)
				continue;

			if (s[i] == s[j])
				pos[s[i] - 'A'] = j, pos2[s[i] - 'A'] = i;
		}
	}

	//	for(int i=0;i<26;i++){

	//		cout<<pos[i]<<" "<<pos2[i]<<endl;

	//	}

	//	cout<<endl;

	for (int i = 0; i < 26; i++)
	{

		for (int j = 0; j < 26; j++)
		{

			if (i == j)
				continue;

			if (pos[i] < pos[j] && pos2[i] > pos2[j])
				continue;

			if (pos[j] > pos2[i] || pos2[j] < pos[i])
				continue;

			if (pos[i] < pos[j] && pos2[i] < pos2[j])

				ans++;
		}
	}

	printf("%d", ans);

	return 0;
}
