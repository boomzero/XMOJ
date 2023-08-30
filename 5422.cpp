#include <bits/stdc++.h>

using namespace std;

int n;

bool cmp(string i, string j)

{

    return (i + j) > (j + i);
}

int main()

{

    cin >> n;

    vector<string> data;

    string temp;

    for (int i = 0; i < n; i++)

    {

        cin >> temp;

        data.push_back(temp);
    }

    sort(data.begin(), data.end(), cmp);

    for (int i = 0; i < n; i++)

    {

        cout << data[i];
    }
}
