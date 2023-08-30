#include <bits/stdc++.h>
using namespace std;
int len, i, a[130];
char s[110];
int main()
{
    a['a'] = a['e'] = a['i'] = a['o'] = a['u'] = 1;
    cin >> s;
    len = strlen(s);
    for (i = 0; i < len - 1; ++i)
    {
        if (a[s[i]] == 0 && s[i] != 'n')
            if (a[s[i + 1]] == 0)
            {
                cout << "NO";
                return 0;
            }
    }
    if (a[s[i]] == 0 && s[i] != 'n')
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return 0;
}
