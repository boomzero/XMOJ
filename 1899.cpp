#include <bits/stdc++.h>

using namespace std;

string a;

int ans;

int main()
{

    cin >> a;

    int len = a.length();

    ans = len / 2;

    for (int i = 0; i < a.length(); ++i)

        if (a[i] == 'p')

            ans--;

    cout << ans;

    return 0;
}
