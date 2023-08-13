#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::string s;
    cin >> s;
    set<std::string> s2;
    for (int i = 0; i < s.length(); i++)
        for (int j = i; j < s.length(); j++)
            s2.insert(s.substr(i, j - i + 1));
    cout << s2.size() - 1 << endl;
    return 0;
}
