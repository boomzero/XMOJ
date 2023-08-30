#include <bits/stdc++.h>
using namespace std;
char a, b;
int main()
{
	cin >> a >> b;
	if (a > b)
		cout << ">";
	else if (a == b)
		cout << "=";
	else
		cout << "<";
	return 0;
}
