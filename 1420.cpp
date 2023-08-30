#include <bits/stdc++.h>
using namespace std;
int DAY[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day[2][5];
int n, t[5000], ans = 0;
bool bad(int year, int mon, int day)
{
    if (day <= DAY[mon])
        return false;
    if (mon == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && day == 29)
        return false;
    return true;
}
void add(int d[], int min)
{
    d[4] += min;
    d[3] += d[4] / 60;
    d[4] %= 60;
    int delta = d[3] / 24;
    d[3] %= 24;
    for (int i = 0; i < delta; ++i)
        if (bad(d[0], d[1], ++d[2]))
        {
            d[2] = 1;
            if (++d[1] == 13)
            {
                d[1] = 1;
                ++d[0];
            }
        }
}
bool good(int d1[], int d2[])
{
    for (int i = 0; i < 5; ++i)
        if (d1[i] != d2[i])
            return d1[i] < d2[i];
    return true;
}
int main()
{
    scanf("%d-%d-%d-%d:%d", &day[0][0], &day[0][1], &day[0][2], &day[0][3], &day[0][4]);
    scanf("%d-%d-%d-%d:%d", &day[1][0], &day[1][1], &day[1][2], &day[1][3], &day[1][4]);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);
    sort(t, t + n);
    for (ans = 0; ans < n; ++ans)
    {
        add(day[0], t[ans]);
        if (!good(day[0], day[1]))
            break;
    }
    cout << ans << endl;
    return 0;
}
