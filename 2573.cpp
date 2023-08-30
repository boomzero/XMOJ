#include <bits/stdc++.h>

using namespace std;

int ans;

int n;

long k;

int a[100010];

int main()
{

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
    }

    int temp = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {

            ans = a[j];

            if (temp == k - 1)
            {

                cout << ans;

                return 0;
            }

            temp++;
        }
    }

    return 0;
}
