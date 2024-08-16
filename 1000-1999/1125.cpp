#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    if (a % 3 == 0)
        cout << "3 ";
    if (a % 5 == 0)
        cout << "5 ";
    if (a % 7 == 0)
        cout << "7 ";
    if (a % 3 && a % 5 && a % 7)
    {
        cout << "n";
    }
    return 0;
}
