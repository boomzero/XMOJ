#include <bits/stdc++.h>
using namespace std;
int n, a[1005], b[1005], c[1005];
int gcd(int i, int j) { return j == 0 ? i : gcd(j, i % j); }
int lcm(int i, int j) { return i * j / gcd(i, j); }
double td(int in) { return (double)in; }
int main()
{
    freopen("equation.in", "r", stdin);
    freopen("equation.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    int aa = a[1], bb = b[1], cc = c[1];
    double ans = numeric_limits<double>::min();
    if (n == 1)
    {
        if (a[1] == 0 && b[1] == 0 && c[1] != 0)
        {
            cout << "No solution!" << endl;
            return 0;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == 0 && b[i] == 0 && c[i] != 0)
        {
            cout << "No solution!" << endl;
            return 0;
        }
        if (a[i] == 0)
        {
            ans = numeric_limits<double>::max();
            continue;
        }
        int bai = a[i], bai1 = a[i + 1], bbi = b[i], bbi1 = b[i + 1], bci = c[i], bci1 = c[i + 1];
        if ((td(a[i]) / td(a[i + 1])) * td(b[i + 1]) != td(b[i]))
        {
            b[i] *= lcm(a[i], a[i + 1]) / a[i];
            c[i] *= lcm(a[i], a[i + 1]) / a[i];
            b[i + 1] *= lcm(a[i], a[i + 1]) / a[i + 1];
            c[i + 1] *= lcm(a[i], a[i + 1]) / a[i + 1];
            int ab = b[i] - b[i + 1], ac = c[i] - c[i + 1];
            if (ans != numeric_limits<double>::min() && ans != td(ac) / td(ab))
            {
                cout << "No solution!" << endl;
                return 0;
            }
            else
                ans = td(ac) / td(ab);
            a[i] = bai, a[i + 1] = bai1, b[i] = bbi, b[i + 1] = bbi1, c[i] = bci, c[i + 1] = bci1;
        }
        else if ((td(a[i]) / td(a[i + 1])) * td(c[i + 1]) != td(c[i]))
        {
            cout << "No solution!" << endl;
            return 0;
        }
    }
    if (ans == numeric_limits<double>::min())
    {
        cout << "OK" << endl;
    }
    else if (ans == numeric_limits<double>::max())
    {
        cout << "No solution!" << endl;
    }
    else
    {
        double x = (td(cc) - bb * ans) / td(aa);
        printf("x=%.3f\n", x);
        printf("y=%.3f\n", ans);
    }
    return 0;
}
