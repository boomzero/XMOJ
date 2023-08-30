#include <bits/stdc++.h>
using namespace std;
int lpow(int times)
{
    int ans = 1;
    for (int i = 0; i < times; ++i)
    {
        ans *= 2;
    }
    return ans;
}
int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    int gans[1000] = {0}, curr = 0;
    int n;
    cin >> n;
    while (true)
    {
        if (n == 0)
            break;
        if (n < 0)
        {
            cout << -1 << endl;
            return 0;
        }
        int i;
        for (i = 1;;)
        {
            i++;
            if (lpow(i) > n && i != 1)
            {
                i--;
                for (int j = 1; j <= curr; ++j)
                {
                    if (j == gans[j])
                    {
                        i--;
                        if (i == 0)
                        {
                            cout << -1 << endl;
                            return 0;
                        }
                    }
                }
                break;
            }
        }
        n -= lpow(i);
        curr++;
        gans[curr] = lpow(i);
    }
    for (int i = 1; i <= curr; ++i)
    {
        cout << gans[i] << " ";
    }
    cout << endl;
    return 0;
}
