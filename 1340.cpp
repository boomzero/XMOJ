#include <bits/stdc++.h>
using namespace std;
char s[110];
int i, len, jump, mx;
int main()
{
    cin >> s;
    for (i = 0, len = strlen(s); i < len; ++i)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U' || s[i] == 'O' || s[i] == 'Y')
            jump = 0;
        else
            ++jump;
        mx = max(mx, jump);
    }
    cout << mx + 1;
    return 0;
}
