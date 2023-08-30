#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, c, d;
    cin >> n;
    for (int a = 2; a <= n; ++a)
    {
        int aa = a * a * a;
        for (int b = 2; b <= a; ++b)
        {
            int bb = b * b * b;
            for (int c = b; c <= a; ++c)
            {
                int cc = c * c * c, dd = aa - bb - cc;
                if (dd >= cc)
                {
                    int x = pow(dd, 1.0 / 3);
                    for (int d = x - 1; d <= x + 1; ++d)
                        if (d * d * d == dd)
                        {
                            cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ") " << endl;
                        }
                }
            }
        }
    }
    return 0;
}
