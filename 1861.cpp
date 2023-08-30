#include <bits/stdc++.h>

using namespace std;

int n, ans, ans_old;

string str;

map<string, int> mp;

map<string, int>::iterator iter;

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> str;

		mp[str] += 1;
	}

	for (iter = mp.begin(); iter != mp.end(); ++iter)
	{

		//		ans_old=ans;

		if (iter->second % 2 == 0)
			ans += iter->second / 2;

		else
			ans += (iter->second) / 2 + 1;

		//		cout<<iter->first.c_str()<<" "<<iter->second<<" "<<ans-ans_old<<endl;
	}

	cout << ans;

	return 0;
}
