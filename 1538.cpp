#include <bits/stdc++.h>
using namespace std;
int n, val;
string str;
deque<int> q;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> str;
        if (str == "PUSH")
        {
            cin >> val;
            q.push_back(val);
        }
        else
        {
            if (q.empty())
                cout << "error" << endl;
            else if (str == "POP")
            {
                cout << q.front() << endl;
                q.pop_front();
            }
            else
            {
                cout << q.back() << endl;
                q.pop_back();
            }
        }
    }
    if (q.empty())
        cout << "empty" << endl;
    else
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop_front();
        }
        cout << endl;
    }
    return 0;
}
