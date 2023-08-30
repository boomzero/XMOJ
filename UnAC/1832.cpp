#include <bits/stdc++.h>
using namespace std;
int f(int p)
{
    if (p == 0 || p == 1)
        return 1;
    return 2 * f(p - 1) + 1;
}
int main()
{
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
