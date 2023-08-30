#include <bits/stdc++.h>

using namespace std;

int n, x, a[110];

long long ans;

int main()
{

    cin >> n >> x;

    int y = x - x / 3;

    for (int i = 0; i < n; ++i)

        cin >> a[i];

    for (int i = 0; i < n; ++i)

        for (int j = i + 1; j < n; ++j)

            for (int k = j + 1; k < n; ++k)
            {

                int tot = a[i] + a[j] + a[k];

                if (y <= tot && tot <= x)

                    ++ans;
            }

    cout << ans;

    return 0;
}
