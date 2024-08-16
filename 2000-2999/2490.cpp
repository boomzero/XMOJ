#include <bits/stdc++.h>
using namespace std;
int cnt[26], len;
char a[110];
int main()
{
    cin >> a;
    len = strlen(a);
    for (int i = 0; i < len; ++i)
    {
        ++cnt[a[i] - 'a'];
    }
    int a = min(cnt['e' - 'a'] / 3, (cnt['n' - 'a'] - 1) / 2);
    int b = min(cnt['i' - 'a'], cnt['t' - 'a']);
    cout << min(a, b);
    return 0;
}
