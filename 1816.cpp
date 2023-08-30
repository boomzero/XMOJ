#include <bits/stdc++.h>
using namespace std;
int n;
set<int> s;
set<int>::iterator iter;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char command;
		cin >> command;
		if (command == 'a')
		{
			int x;
			cin >> x;
			s.insert(x);
		}
		else if (command == 'd')
		{
			int x;
			cin >> x;
			s.erase(x);
		}
		else if (command == 'q')
		{
			printf("%d\n", *s.begin());
			s.erase(*s.begin());
		}
	}
	return 0;
}
