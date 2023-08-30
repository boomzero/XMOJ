#include <bits/stdc++.h>
using namespace std;
int n, arr[105] = {0};
void dfs(int val, int pos, bool nn)
{
    arr[pos] = val;
    if (val == 1 && !nn)
    {
        for (int i = 1; i <= 2 * n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        exit(0);
    }
    if (nn)
    {
        if (arr[pos + val + 1] == 0)
            dfs(val, pos + val + 1, false);
    }
    else
    {
        for (int i = 1; i <= 2 * n; ++i)
        {
            if (arr[i] == 0 && arr[i + val] == 0 && i + val <= 2 * n)
                dfs(val - 1, i, true);
        }
    }
    arr[pos] = 0;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i)
    {
        dfs(n, i, true);
    }
    return 0;
}
