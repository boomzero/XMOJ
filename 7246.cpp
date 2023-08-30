#include <bits/stdc++.h>
using namespace std;
string s, cv;
set<string> var;
void dfs(int rm)
{ // 0:head 1:tail
    char bk;
    if (rm)
    {
        bk = s[s.length() - 1];
        s.pop_back();
    }
    else
    {
        bk = s[0];
        s.erase(s.begin());
    }
    cv.push_back(bk);
    if (s.length() == 0)
    {
        var.insert(cv);
    }
    else
    {
        dfs(0);
        dfs(1);
    }
    if (rm)
    {
        s.push_back(bk);
    }
    else
    {
        string tmp;
        tmp.push_back(bk);
        s.insert(0, tmp);
    }
    cv.pop_back();
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> s;
    dfs(0);
    dfs(1);
    cout << var.size() << endl;
    return 0;
}
