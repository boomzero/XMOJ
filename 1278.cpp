#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
const double PI = 3.141592653589793;
int n, f;
double tj[10001];
bool good(double res)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += int(tj[i] / res);
    }
    return sum >= f;
}
int main()
{
    double left = 0, right = 0, tmp;
    // 读取数据
    cin >> n >> f;
    f++;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        tj[i] = tmp * tmp * PI;
        if (tj[i] > right)
            right = tj[i];
    }
    // 二分遍历查找
    while (right - left > 1e-6)
    {
        double mid = (left + right) / 2;
        if (good(mid))
            left = mid;
        else
            right = mid;
    }
    printf("%.3lf\n", left);
    return 0;
}
