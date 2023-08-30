#include <bits/stdc++.h>
using namespace std;
int len, cnt, i, j;
char s[110];
int main()
{
    cin >> s;
    len = strlen(s);
    for (i = 0; i < len; ++i)
    {
        if (s[i] == '1')
        {
            break;
        }
    }
    for (j = i + 1; j < len; ++j)
    {
        if (s[j] == '0')
        {
            ++cnt;
        }
    }
    if (cnt >= 6)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}
