#include <bits/stdc++.h>

using namespace std;

string s, s1, s2;

int main()

{

    //    char c;

    //    while(cin >> c, c!=',') s += c;

    //    while(cin >> c, c!=',') s1 += c;

    //    while(cin >> c) s2 += c;

    cin >> s >> s1 >> s2;

    if (s.size() < s1.size() || s.size() < s2.size())

        cout << -1;

    else

    {

        int l = 0;

        while (l + s1.size() <= s.size())

        {

            int k = 0;

            while (k < s1.size())

            {

                if (s[l + k] != s1[k])
                    break;

                k++;
            }

            if (k == s1.size())
                break;

            l++;
        }

        int r = s.size() - s2.size();

        while (r >= 0)

        {

            int k = 0;

            while (k < s2.size())

            {

                if (s[r + k] != s2[k])
                    break;

                k++;
            }

            if (k == s2.size())
                break;

            r--;
        }

        l += s1.size() - 1;

        if (l >= r)
            puts("-1");

        else
            printf("%d", r - l - 1);
    }

    return 0;
}
