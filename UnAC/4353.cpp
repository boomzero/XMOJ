#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, n;
    cin >> k >> n;
    vector<vector<int>> rank;
    rank.resize(k + 1);
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int tmp;
            cin >> tmp;
            rank[i].push_back(tmp);
        }
    }
    set<pair<int, int>> ans, trash;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int l = j + 1; l < n; ++l)
            {
                auto tmp = make_pair(rank[i][j], rank[i][l]), wrong = make_pair(rank[i][l], rank[i][j]);
                ans.insert(tmp);
                trash.insert(tmp);
                if (trash.count(wrong))
                {
                    ans.erase(wrong);
                    ans.erase(tmp);
                }
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}
