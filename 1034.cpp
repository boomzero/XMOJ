#include <bits/stdc++.h>
using namespace std;
int n, pencil[2][4], minn = 1000000000;
int main()
{
	freopen("pencil.in", "r", stdin);
	freopen("pencil.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		cin >> pencil[i][0] >> pencil[i][1];
	}
	if (n % pencil[0][0] != 0)
		minn = min(minn, pencil[0][1] * (n / pencil[0][0] + 1));
	else if (n % pencil[0][0] == 0)
		minn = min(minn, pencil[0][1] * (n / pencil[0][0]));
	if (n % pencil[1][0] != 0)
		minn = min(minn, pencil[1][1] * (n / pencil[1][0] + 1));
	else if (n % pencil[1][0] == 0)
		minn = min(minn, pencil[1][1] * (n / pencil[1][0]));
	if (n % pencil[2][0] != 0)
		minn = min(minn, pencil[2][1] * (n / pencil[2][0] + 1));
	else if (n % pencil[2][0] == 0)
		minn = min(minn, pencil[2][1] * (n / pencil[2][0]));
	cout << minn;
	fclose(stdout);
	fclose(stdout);
	return 0;
}
