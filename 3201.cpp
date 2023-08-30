#include <bits/stdc++.h>

using namespace std;

int n, a[1010];

int x, y;

long mn = 1000000100;

int mnd;

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
    }

    cin >> x;

    for (int i = 0; i < n; i++)
    {

        y = abs(x - a[i]);

        if (mn > y)
        {

            mn = y;

            mnd = a[i];
        }

        else if (mn == y)
        {

            if (mnd > a[i])
            {

                mnd = a[i];

                mn = y;
            }

            else
            {

                continue;
            }
        }
    }

    cout << mnd;

    return 0;
}
