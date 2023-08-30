#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, ba;
    getline(cin, a);
    ba = a;
    reverse(a.begin(), a.end());
    stringstream ss(a);
    string b;
    stack<string> s;
    while (ss >> b)
    {
        s.push(b);
    }
    int cs = 0;
    while (!s.empty())
    {
        cout << s.top();
        cs += s.top().length();
        while (ba[cs] == ' ')
        {
            putchar(' ');
            cs++;
        }
        s.pop();
    }
    cout << endl;
    return 0;
}
