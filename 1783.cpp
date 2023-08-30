#include <cstdio>
#include <iostream>
#include <string>
#define MAXN 400000
using namespace std;

const unsigned MOD = 1e7 + 9;
unsigned hs[MAXN + 5], mul[MAXN + 5];

int main()
{
    ios::sync_with_stdio(0);
    mul[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        mul[i] = mul[i - 1] * MOD;
    string s;
    int n;
    while (cin >> s)
    {
        n = s.size();
        s = ' ' + s;
        for (int i = 1; i <= n; ++i)
            hs[i] = hs[i - 1] * MOD + (unsigned)s[i];
        for (int i = 1; i <= n; ++i)
        {
            if (hs[i] == hs[n] - hs[n - i] * mul[i])
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
