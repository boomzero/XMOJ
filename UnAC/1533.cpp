#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
            s.push(i);
        else
        {
            cout << s.top() << " " << i << endl;
            s.pop();
        }
    }
    return 0;
}
