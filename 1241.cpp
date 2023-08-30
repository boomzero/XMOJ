#include <bits/stdc++.h>

#include <cstring>

using namespace std;

int n, temp, pos, alen, sum[1010], a[1010], sumlen;

bool out;

int main(int argc, const char *argv[])
{

    cin >> n;

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];
    }

    for (int i = n - 1; i > 0; i--)

    {

        for (int j = 0; j < i; j++)

        {

            if (a[j] > a[j + 1])

            {

                swap(a[j], a[j + 1]);
            }
        }
    }

    alen = n;

    for (int i = 0; i < n; i++)

    {

        if (a[i] != a[i + 1])

        {

            sum[temp] = a[i];

            temp += 1;

            pos = i + 2;

            while (a[pos] == a[i])

            {

                i += 1;

                pos += 1;
            }
        }
    }

    for (int i = 0; i < alen; i++)

    {

        if (sum[i] != 0)

        {

            sumlen += 1;
        }
    }

    cout << sumlen << endl;

    for (int i = 0; i < sumlen; i++)

    {

        cout << sum[i];

        if (i < sumlen - 1)

        {

            cout << " ";
        }
    }

    return 0;
}
