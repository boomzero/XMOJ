#include <bits/stdc++.h>
using namespace std;
int main()
{
    // a[i]: 第i个人的礼物送给谁了
    int n, a[110];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[j] == i)
            {
                cout << j << " ";
                break;
            }
    return 0;
}
