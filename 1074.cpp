#include <bits/stdc++.h>
using namespace std;
string a, b, c;
char res;
int main()
{
    cin >> a;
    cin >> b;
    cin >> c;
    int i, j, k;
    int sa, sb, sc;
    char ch;
    i = j = k = 0;
    sa = a.length();
    sb = b.length();
    sc = c.length();
    ch = a[i++];
    while (i <= sa && j <= sb && k <= sc)
    {
        if (ch == 'a')
        {
            if (i == sa)
            {
                res = 'A';
                break;
            }
            ch = a[i++];
            continue;
        }
        if (ch == 'b')
        {
            if (j == sb)
            {
                res = 'B';
                break;
            }
            ch = b[j++];
            continue;
        }
        if (ch == 'c')
        {
            if (k == sc)
            {
                res = 'C';
                break;
            }
            ch = c[k++];
            continue;
        }
    }
    cout << res << endl;
    return 0;
}
