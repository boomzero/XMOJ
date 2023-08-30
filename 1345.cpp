#include <bits/stdc++.h>
using namespace std;
char s[110], t[110];
int ls, lt;
int i, j;
bool isok = false;
int main()
{
    cin >> s >> t;
    ls = strlen(s);
    lt = strlen(t);
    if (ls != lt)
        cout << "NO";
    else
    {
        for (i = 0, j = ls - 1; i < ls; ++i, --j)
            if (s[i] != t[j])
            {
                cout << "NO";
                return 0;
            }
        cout << "YES";
    }
    return 0;
}
