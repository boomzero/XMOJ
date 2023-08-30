#include <bits/stdc++.h>

using namespace std;

int main()

{

    int n, m, a, b = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {

        cin >> a;

        if (a == m)

            b++;
    }

    cout << b << endl;

    return 0;
}
