#include <bits/stdc++.h>

using namespace std;

char s[210];

int ls, found;

int main()
{

    cin >> s;

    ls = strlen(s);

    while (true)
    {

        found = false;

        if (ls > 2 && (s[ls - 1] == 'r' && s[ls - 2] == 'e' || s[ls - 1] == 'y' && s[ls - 2] == 'l'))
        {

            s[ls - 2] = '\0';

            ls -= 2;

            found = true;
        }

        if (ls > 3 && s[ls - 1] == 'g' && s[ls - 2] == 'n' && s[ls - 3] == 'i')
        {

            s[ls - 3] = '\0';

            ls -= 3;

            found = true;
        }

        if (!found)

            break;
    }

    cout << s;

    return 0;
}
