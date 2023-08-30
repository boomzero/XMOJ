#include <bits/stdc++.h>

using namespace std;

int main()

{

    freopen("coin.in", "r", stdin);

    freopen("coin.out", "w", stdout);

    int n = 1, k, sum = 0;

    cin >> k;

    for (int i = 1; i <= k;)
    {

        for (int j = 1; j <= n && i <= k; j++)
        {

            sum += n;

            i++;
        }

        n++;
    }

    cout << sum;

    return 0;
}
