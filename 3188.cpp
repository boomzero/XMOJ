#include <bits/stdc++.h>
using namespace std;
int len, a[200];
char s[110];
int main()
{
    a['a'] = a['e'] = a['i'] = a['o'] = a['u'] = a['y'] = 1;
    cin >> len >> s;
    cout << s[0];
    for (int i = 1; i < len; ++i)
    {
        if (a[s[i - 1]] == 0 || a[s[i]] == 0)
            cout << s[i];
    }
    return 0;
}
