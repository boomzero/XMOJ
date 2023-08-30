#include <bits/stdc++.h>

using namespace std;

struct tScore
{

    int id, tot;

} s[1010];

int n, a, ans;

int main()
{

    cin >> n;

    for (int i = 0; i < n; ++i)
    {

        for (int j = 0; j < 4; ++j)
        {

            cin >> a;

            s[i].tot += a;
        }

        s[i].id = i + 1;
    }

    for (int i = n - 1; i > 0; --i)

        for (int j = 0; j < i; ++j)
        {

            bool f = false;

            if (s[j].tot < s[j + 1].tot)

                f = true;

            else if (s[j].tot == s[j + 1].tot)

                f = s[j].id > s[j + 1].id;

            if (f)

                swap(s[j], s[j + 1]);
        }

    for (int i = 0; i < n; ++i)

        if (s[i].id == 1)
        {

            ans = i + 1;

            break;
        }

    cout << ans;

    return 0;
}
