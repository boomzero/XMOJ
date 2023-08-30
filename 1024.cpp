#include <bits/stdc++.h>

using namespace std;

int used[36], temp, all, ok;

char a[110];

int main()
{

    cin >> a;

    for (int i = 0; i < strlen(a); i++)

    {

        temp = a[i] - 97;

        used[temp] += 1;
    }

    for (int i = 0; i < 26; i++)

    {

        if (used[i] != 0 && used[i] % 2 == 0)

        {

            ok += 1;
        }
    }

    for (int i = 0; i < 26; i++)

    {

        if (used[i] != 0)

        {

            all += 1;
        }
    }

    if (all == ok)

    {

        cout << "Yes";
    }

    else
    {

        cout << "No";
    }

    return 0;
}
