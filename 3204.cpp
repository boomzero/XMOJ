#include <bits/stdc++.h>

using namespace std;

int n, m, quan[1010], total;

long a[1010];

int main(int argc, const char *argv[])
{

    cin >> n;

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];

        total += a[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++)

    {

        cin >> quan[i];

    } // cin until here

    for (int j = n; j > 0; j--)

    {

        for (int i = 0; i < n; i++)

        {

            if (a[i] < a[i + 1])

            {

                swap(a[i], a[i + 1]);
            }
        }

    } // swap until here

    int ok = 0;

    for (int i = 0; i < m; i++)

    {

        total = total - a[quan[i] - 1];

        cout << total; // not ok!

        if (ok < m - 1)

        {

            cout << endl;

            ok += 1;

        } // ok!

        total = total + a[quan[i] - 1];

    } // change and cout until here

    return 0;
}
