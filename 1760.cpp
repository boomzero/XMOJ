#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{

	cin >> n;

	if (n & (n - 1))

		cout << "No";

	else

		cout << "Yes";

	return 0;
}
