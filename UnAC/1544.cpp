#include <bits/stdc++.h>
using namespace std;
int l1, l2, f[1500][1500] = {{0}}, mans = 0;
string a, b;
int main()
{
    cin >> a >> b;
    l1 = a.length(), l2 = b.length();
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                f[i][j] = f[i - 1][j - 1] + 1;
                if (f[i][j] > mans)
                    mans = f[i][j];
            }
        }
    }
    cout << mans << endl;
    return 0;
}
