#include <bits/stdc++.h>
using namespace std;
double cunt, all, ok;
char a[510], b[510];
int main(int argc, const char *argv[])
{
    cin >> cunt;
    cin >> a >> b;
    all = strlen(a);
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == b[i])
        {
            ok += 1;
        }
    }
    if (ok / all >= cunt)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}
