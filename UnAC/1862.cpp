#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<string> c;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string in;
        cin >> in;
        if (in[0] == '+')
        {
            in.erase(in.begin());
            c.insert(in);
        }
        else if (in[0] == '-')
        {
            in.erase(in.begin());
            c.erase(in);
        }
        else
        {
            cout << c.size() << endl;
            for (const string &j : c)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
