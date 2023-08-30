#include <bits/stdc++.h>
using namespace std;
int dsk[100005];
deque<int> col[100005];
int main()
{
    int n, k = 0, cofs = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> dsk[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        bool matched = false;
        if (dsk[i] < cofs)
        {
            cout << i - 1 << endl;
            return 0;
        }
        for (int j = 1; j <= k; ++j)
        {
            if (!col[j].empty() && col[j].front() < dsk[i])
            {
                if (col[j].back() > dsk[i])
                {
                    for (int l = 1; l < j; ++l)
                    {
                        while (!col[l].empty())
                        {
                            cofs = max(cofs, col[l].front());
                            col[l].pop_front();
                        }
                    }
                    while (!col[j].empty() && col[j].front() < dsk[i])
                    {
                        cofs = max(cofs, col[j].front());
                        col[j].pop_front();
                    }
                    col[j].push_front(dsk[i]);
                    matched = true;
                    break;
                }
            }
            else if (!col[j].empty() && col[j].front() > dsk[i])
            {
                col[j].push_front(dsk[i]);
                matched = true;
                break;
            }
        }
        if (!matched)
        {
            k++;
            col[k].push_front(dsk[i]);
        }
    }
    cout << n << endl;
    return 0;
}
