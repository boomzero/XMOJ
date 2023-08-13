#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
std::string Original, Answer;
int main()
{
    freopen("order.in", "r", stdin);
    freopen("order.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        char s[2];
        scanf("%s", s);
        Original += s[0];
    }
    ll Left = 0;
    ll Right = n - 1;
    while (Left <= Right)
    {
        if (Original[Left] < Original[Right])
        {
            Answer += Original[Left];
            Left++;
        }
        else if (Original[Left] > Original[Right])
        {
            Answer += Original[Right];
            Right--;
        }
        else
        {
            ll Left2 = Left + 1, Right2 = Right - 1;
            while (Left2 <= Right2 && Original[Left2] == Original[Right2])
                Left2++, Right2--;
            if (Left2 > Right2)
            {
                Answer += Original[Left];
                Left++;
            }
            else if (Original[Left2] < Original[Right2])
            {
                Answer += Original[Left];
                Left++;
            }
            else
            {
                Answer += Original[Right];
                Right--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%c", Answer[i]);
        if ((i + 1) % 80 == 0)
            printf("\n");
    }
    return 0;
}
