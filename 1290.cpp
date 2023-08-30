#include <bits/stdc++.h>
#include <cstring>
using namespace std;
char a[110], ans[110], temp;
int alen, i;
int main(int argc, const char *argv[])
{
    cin >> a;
    while (a[i] != '\0')
    {
        alen += 1;
        i += 1;
    }
    for (int i = 0; i < alen; i++)
    {
        if (i < alen - 1)
        {
            ans[i] = a[i] + a[i + 1];
        }
        else
        {
            ans[i] = a[i] + a[0];
        }
    }
    for (int i = 0; i < alen; i++)
    {
        cout << ans[i];
    }
    return 0;
}
