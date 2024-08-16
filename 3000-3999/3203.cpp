#include <bits/stdc++.h>
using namespace std;
int len, ans;
char s[110];
int main()
{
    cin >> s;
    len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '0')
            break;
        ++ans;
    }
    if (ans == len)
        cout << len;
    else
        cout << ans + 1;
    return 0;
}
