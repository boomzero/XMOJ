#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y, z;
    cin >> n >> x >> y;
    z = n - y / x;
    if (y % x != 0)
        --z;
    if (z < 0)
        z = 0;
    cout << z << endl;
    return 0;
}
