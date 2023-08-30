#include <iostream>
using namespace std;
int main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n, L, R;
    cin >> n >> L >> R;
    // 糖果区间大于或等于n-1（模长最大值），即超过一个周期，奖励糖果的最大值是n-1.
    if (R - L >= n - 1)
    { // 7 16 23 -> 6
        cout << n - 1;
    }
    // 在一个周期内。
    else if (L % n <= R % n)
    { // 10 14 18 -> 8
        cout << R % n;
    }
    else if (L % n > R % n)
    { // 10 14 20
        cout << n - 1;
    }
    return 0;
}
