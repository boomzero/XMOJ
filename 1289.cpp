#include <bits/stdc++.h>
using namespace std;
string a, b;
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a[0] == b[0])
			cout << "Tie" << endl;
		else if (a[0] == 'R' && b[0] == 'S')
			cout << "Player1" << endl;
		else if (a[0] == 'R' && b[0] == 'P')
			cout << "Player2" << endl;
		else if (a[0] == 'S' && b[0] == 'R')
			cout << "Player2" << endl;
		else if (a[0] == 'S' && b[0] == 'P')
			cout << "Player1" << endl;
		else if (a[0] == 'P' && b[0] == 'R')
			cout << "Player1" << endl;
		else
			cout << "Player2" << endl;
	}
	return 0;
}
