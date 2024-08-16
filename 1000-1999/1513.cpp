#include <bits/stdc++.h>
using namespace std;
struct lianbiao
{
    int val, nxt;
} s[200010];
int tot = 0;
void add(int idx, int x)
{
    ++tot;
    s[tot].val = x;
    s[tot].nxt = s[idx].nxt;
    s[idx].nxt = tot;
}
int main()
{
    int n, x, rear = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        add(rear, x);
        rear = s[rear].nxt;
    }
    scanf("%d", &x);
    int p = 0;
    while (s[p].nxt)
    {
        if (s[s[p].nxt].val == x)
            s[p].nxt = s[s[p].nxt].nxt;
        else
            p = s[p].nxt;
    }
    p = s[0].nxt;
    while (p)
    {
        printf("%d ", s[p].val);
        p = s[p].nxt;
    }
    printf("\n");
    return 0;
}
