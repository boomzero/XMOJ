#include <bits/stdc++.h>

using namespace std;

int n, s, a[110], total;

int main(int argc, const char *argv[])
{

    cin >> n >> s;

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];
    }

    for (int i = 0; i < n; i++)

    {

        for (int j = 0; j < n; j++)

        {

            if (a[i] > a[i + 1])

            {

                swap(a[i], a[i + 1]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++)

    {

        total = total + a[i];
    }

    if (total > s)

    {

        cout << "NO";
    }

    else
    {

        cout << "YES";
    }

    return 0;
}
