#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, value, father[N];
int find(int);
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> value >> father[i];
    int k = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x = 0;
        cin >> x;
        cout << find(x) << endl;
    }
    return 0;
}
int find(int x)
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (father[i] == x)
        {
            ans++;
        }
    }
    return ans++;
}
