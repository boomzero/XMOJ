#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int max;
    cin >> max;
    int ans = 1;
    vector<int> mis;
    mis.push_back(max);
    for (int i = 0; i < n - 1; ++i)
    {
        int tmp;
        cin >> tmp;
        if (tmp > max)
        {
            ans++;
            mis.push_back(tmp);
            max = tmp;
        }
        else
        {
            sort(mis.begin(), mis.end());
            for (int &j : mis)
            {
                if (j >= tmp)
                {
                    j = tmp;
                    break;
                }
            }
            max = mis[mis.size() - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
