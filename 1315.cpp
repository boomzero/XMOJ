#include <bits/stdc++.h>

using namespace std;

int x, y, len, len1, len2, limit, ans = 0;

string s1, s2;

int main()

{

    cin >> s1 >> s2;

    len1 = s1.size();

    len2 = s2.size();

    limit = min(len1, len2);

    s1 += s1;

    s2 += s2;

    for (int i = 0; i < len1; i++)
    {

        for (int j = 0; j < len2; j++)
        {

            len = 0;

            x = i;

            y = j;

            while (s1[x++] == s2[y++] && len < limit)
                len++;

            if (len > ans)
                ans = len;
        }
    }

    cout << ans;

    return 0;
}
