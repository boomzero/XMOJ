#include <bits/stdc++.h>
using namespace std;
bool isPrime(int m)
{
    // 单独处理0、1
    if (m < 2)
        return false;
    // 单独处理2、3
    if (m < 4)
        return true;
    // 单独处理偶数
    if (m % 2 == 0)
        return false;
    // 从3开始，用每个奇数来判断
    int i = 3;
    while (m % i != 0 && i * i <= m)
        i += 2;
    if (i * i > m)
        return true;
    return false;
}
int main()
{
    for (int i = 1003; i < 3000; i += 2)
    {
        if (isPrime(i % 10) && isPrime(i % 100) && isPrime(i % 1000) && isPrime(i))
            cout << i << " ";
    }
    return 0;
}
