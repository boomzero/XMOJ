#include <bits/stdc++.h>
using namespace std;
int n, p;
int main()
{
    cin >> n;
    p = 1;
    for (int i = 1; i < n; i++)
    {
        p += i;
        if (p > n)
        {
            p -= n;
        }
        cout << p << " ";
    }
    return 0;
}
