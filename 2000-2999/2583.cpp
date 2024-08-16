#include <bits/stdc++.h>
using namespace std;
int a[6], one, two, add;
bool isok()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == i)
            {
                continue;
            }
            for (int z = 0; z < 6; z++)
            {
                if (z == j)
                {
                    continue;
                }
                if (z == i)
                {
                    continue;
                }
                if (a[i] + a[j] + a[z] == add - a[i] - a[j] - a[z])
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
        add += a[i];
    }
    for (int i = 6; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
    if (isok() == true)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
