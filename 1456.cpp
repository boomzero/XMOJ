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
    int n, flag = 0;
    cin >> n;
    for (int i = 3; i <= n - 2; i += 2)
        // 确保调用时不会传入偶数
        if (isPrime(i) && isPrime(i + 2))
        {
            cout << i << " " << i + 2 << endl;
            flag = 1;
        }
    if (!flag)
        cout << "empty";
    return 0;
}
