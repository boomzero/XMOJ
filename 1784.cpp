#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define b 31
#define N 2000100
using namespace std;
unsigned int ha[N], p[N], n, ha1 = 0;
char s1[N];
bool check(int x, int y)
{
    int t;
    if (ha1)
    {
        t = ha[y] - ha[x - 1] * p[y - x + 1];
        if (t != ha1)
            return 1;
        else
            return 0;
    }
    else
    {
        ha1 = ha[y] - ha[x - 1] * p[y - x + 1];
        return 1;
    }
}
int main()
{
    p[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = p[i - 1] * b;
    scanf("%d %s", &n, s1);
    ha[0] = s1[0] - 'A' + 1;
    for (int i = 1; i < n; i++)
        ha[i] = ha[i - 1] * b + (s1[i] - 'A' + 1);
    //  for(int i=0;i<n;i++)
    //      cout<<ha[i]<<" ";
    //  cout<<endl;
    int ans = 0, w;
    if (n % 2 == 0)
    {
        printf("NOT POSSIBLE\n");
        return 0;
    }
    if ((ha[n / 2] - ha[0] * p[n / 2]) == (ha[n - 1] - ha[n / 2] * p[n / 2]))
    {
        if (check(1, n / 2))
        {
            ans++;
            w = 0;
        }
    }
    //  cout<<ha[n/2-1]<<" "<<ha[n-2]-ha[n/2-1]*p[n/2]<<" ";
    if (ha[n / 2 - 1] == (ha[n - 2] - ha[n / 2 - 1] * p[n / 2]))
    {
        if (check(0, n / 2 - 1))
        {
            ans++;
            w = n - 1;
        }
    }
    if (ha[n / 2 - 1] == (ha[n - 1] - ha[n / 2] * p[n / 2]))
    {
        if (check(0, n / 2 - 1))
        {
            ans++;
            w = n / 2;
        }
    }
    for (int k = 1; k < n / 2; k++)
    {
        unsigned int t1 = ha[k - 1] * p[n / 2 - k] + ha[n / 2] - ha[k] * p[n / 2 - k];
        unsigned int t2 = ha[n - 1] - ha[n / 2] * p[n / 2];
        //  cout<<t1<<" "<<t2<<endl;
        if (t1 == t2 && check(n / 2 + 1, n - 1))
        {
            ans++;
            w = k;
        }
    }
    for (int k = n / 2 + 1; k < n - 1; k++)
    {
        unsigned int t1 = ha[n / 2 - 1];
        unsigned int t2 = (ha[k - 1] - ha[n / 2 - 1] * p[k - n / 2]) * p[n - k - 1] + (ha[n - 1] - ha[k] * p[n - k - 1]);
        //  cout<<t1<<" "<<t2<<endl;
        if (t1 == t2 && check(0, n / 2 - 1))
        {
            ans++;
            w = k;
        }
    }
    if (ans == 0)
        printf("NOT POSSIBLE\n");
    else if (ans > 1)
        printf("NOT UNIQUE\n");
    else
    {
        if (w == 0)
        {
            for (int i = 1; i <= n / 2; i++)
                printf("%c", s1[i]);
        }
        else if (w == n - 1)
        {
            for (int i = 0; i < n / 2; i++)
                printf("%c", s1[i]);
        }
        else if (w == n / 2)
        {
            for (int i = 0; i < n / 2; i++)
                printf("%c", s1[i]);
        }
        else if (w < n / 2)
        {
            for (int i = 0; i <= n / 2; i++)
                if (i == w)
                    continue;
                else
                    printf("%c", s1[i]);
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
                printf("%c", s1[i]);
        }
    }

    return 0;
}
