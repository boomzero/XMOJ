#include <bits/stdc++.h>
using namespace std;
map<long long, long long> fab;
long long f(int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (!fab.count(n))
    {
        fab[n] = (f(n - 1) % 1000000007 + f(n - 2) % 1000000007) % 1000000007;
    }
    return fab[n];
}
int main()
{
    fab[1] = fab[2] = 1;
    int n;
    cin >> n;
    f(10001);
    for (int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        cout << fab[p] << endl;
    }
    return 0;
}
