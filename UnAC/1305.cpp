#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.length() > 1)
    {
        string ee = s.substr(s.length() - 2, 2), se = s.substr(s.length() - 3, 3);
        while (ee == "er" || ee == "ly" || se == "ing")
        {
            if (ee == "er" || ee == "ly")
            {
                s.pop_back();
                s.pop_back();
            }
            if (se == "ing")
            {
                s.pop_back();
                s.pop_back();
                s.pop_back();
            }
            if (s.length() > 2)
            {
                ee = s.substr(s.length() - 2, 2), se = s.substr(s.length() - 3, 3);
            }
            else
            {
                ee.clear();
                se.clear();
            }
        }
    }
    cout << s << endl;
    return 0;
}
