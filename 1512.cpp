#include <bits/stdc++.h>

using namespace std;

int a, n, ans;

int main()
{

	while (cin >> a >> n)
	{

		queue<int> q1, q2;

		while (n--)
		{

			ans = a;

			q1.push(2 * a + 1);

			q2.push(3 * a + 1);

			int t1 = q1.front(), t2 = q2.front();

			if (t1 < t2)
			{

				a = t1;

				q1.pop();
			}

			else if (t1 > t2)
			{

				a = t2;

				q2.pop();
			}

			else
			{

				a = t1;

				q1.pop();

				q2.pop();
			}
		}

		cout << ans << endl;
	}

	return 0;
}
