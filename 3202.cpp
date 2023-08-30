#include <bits/stdc++.h>

using namespace std;

int l, r, n, ans, i, zu;

int main()
{

    cin >> n;

    for (i = 0; i < n; i++)

    {

        cin >> l >> r;

        zu = (r - l + 1) / 2;

        if (l % 2 == 1 && r % 2 == 0)

        {

            ans = zu;

            cout << ans;

            if (i < n - 1)
            {

                cout << endl;
            }
        }
        else if (l % 2 == 0 && r % 2 == 1)

        {

            ans = zu;

            cout << "-" << ans;

            if (i < n - 1)
            {

                cout << endl;
            }
        }
        else if (l % 2 == 1 && r % 2 == 1)
        {

            ans = zu - r;

            cout << ans;

            if (i < n - 1)
            {

                cout << endl;
            }
        }
        else if (l % 2 == 0 && r % 2 == 0)
        {

            ans = r - zu;

            cout << ans;

            if (i < n - 1)
            {

                cout << endl;
            }
        }

        ans = 0;
    }

    return 0;
}
