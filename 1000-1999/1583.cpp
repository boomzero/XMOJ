#include <bits/stdc++.h>
using namespace std;
int n, m1 = 100000, m2 = 0;
int main()
{
    cin >> n;
    for (int i = 0; i <= n / 2; ++i)
    {
        int x = i * 2;
        for (int j = 0, y = 0; y + x <= n; ++j, y += 4)
            if (x + y == n)
            {
                m1 = min(m1, i + j);
                m2 = max(m2, i + j);
            }
    }
    if (m1 == 100000)
        m1 = 0;
    cout << m1 << " " << m2 << endl;
    return 0;
}
