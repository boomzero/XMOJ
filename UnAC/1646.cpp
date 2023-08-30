#include <bits/stdc++.h>
using namespace std;
long long pow_mod(int a, int n, int m)
{
    if (n == 0)
        return 1;
    int x = pow_mod(a, n / 2, m);
    long long ans = (long long)x * x % m;
    if (n % 2 == 1)
        ans = ans * a % m;
    return ans;
}
int main()
{
    long long n, m, k, x;
    cin >> n >> m >> k >> x;
    cout << (x % n + m * pow_mod(10, k, n)) % n << endl;
    return 0;
}
