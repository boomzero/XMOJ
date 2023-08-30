#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<pair<string, string>> s;
    for (int i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        if (s.count(make_pair(a, b)))
        {
            cout << "I am angry" << endl;
            return 0;
        }
        else
        {
            s.insert(make_pair(a, b));
        }
    }
    cout << "Nice hand" << endl;
    return 0;
}
