#include <bits/stdc++.h>

using namespace std;

void NO()
{

    cout << "-1" << endl;

    exit(0);
}

int main()
{

    freopen("d.in", "r", stdin);

    freopen("d.out", "w", stdout);

    string s;

    cin >> s;

    int n = s.size();

    if (s[0] == '0' || s[n - 1] == '1')
        NO();

    for (int i = 0; i < (n - 1) / 2; i++)

        if (s[i] != s[n - i - 2])
            NO();

    set<pair<int, int>> st;

    for (int i = 1; i <= n; i++)
        st.insert(make_pair(1, i));

    vector<pair<int, int>> e;

    for (int i = 0; i < n; i++)
    {

        if (s[i] == '1')
        {

            int u = st.rbegin()->second;

            int sz = st.rbegin()->first;

            int x = u;

            st.erase(make_pair(sz, u));

            int need = i + 1 - sz + 1;

            while (need)
            {

                auto it = st.upper_bound(make_pair(need, 1e9));

                if (it == st.begin())
                    NO();

                it--;

                int v = it->second;

                int szz = it->first;

                st.erase(make_pair(szz, v));

                need -= szz;

                e.push_back(make_pair(u, v));

                sz += szz;

                x = v;
            }

            st.insert(make_pair(i + 2, x));
        }
    }

    for (pair<int, int> a : e)

        cout << a.first << ' ' << a.second << '\n';
}
