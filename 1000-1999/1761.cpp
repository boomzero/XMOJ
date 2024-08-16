#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p = 1, num = 0;
    cin >> n;
    while (p <= n)
    {
        p *= 2;
        ++num;
    }
    cout << num;
    return 0;
}
