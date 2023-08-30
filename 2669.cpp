#include <bits/stdc++.h>
using namespace std;
int n, x, y, s = 1, mx = 1;
int main()
{
    cin >> n >> y;
    for (int i = 1; i < n; ++i)
    {
        cin >> x;
        if (x <= y)
            s = 1;
        else
        {
            ++s;
            if (s > mx)
                mx = s;
        }
        y = x;
    }
    cout << mx;
    return 0;
}
