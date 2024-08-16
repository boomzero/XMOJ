#include <bits/stdc++.h>
using namespace std;
long long n, A, B;
int main()
{
    cin >> n >> A >> B;
    for (long long i = 1, a, b, x; i < n; ++i)
    {
        cin >> a >> b;
        x = max((A + a - 1) / a, (B + b - 1) / b);
        A = a * x;
        B = b * x;
    }
    cout << A + B << endl;
    return 0;
}
