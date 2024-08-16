#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long a, b, x, y;
void god(long long a, long long b, long long &x, long long &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return;
    }
    god(b, a%b, x, y);
    int t = x;
    x = y;
    y = t - a / b*y;
}
int main()
{
    scanf("%lld%lld", &a, &b);
    god(a, b, x, y);
    x = (x % b + b) % b;
    printf("%lld\n", x);
    return 0;
}
