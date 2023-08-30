#include <bits/stdc++.h>
using namespace std;
struct Num
{
    int x, y;
} h[1000010];
int n, x, y, tot;
char op[10];
bool cmp(const Num &n1, const Num &n2)
{
    if (n1.x != n2.x)
        return n1.x < n2.x;
    return n1.y > n2.y;
}
void push(int x, int y)
{
    h[++tot] = (Num){x, y};
    int k = tot;
    while (k > 1)
    {
        int i = k / 2;
        if (cmp(h[k], h[i]))
        {
            swap(h[i], h[k]);
            k = i;
        }
        else
            break;
    }
}
Num pop()
{
    Num ans = h[1];
    swap(h[1], h[tot--]);
    int k = 1;
    while (k + k <= tot)
    {
        int i = k + k;
        if (i + 1 <= tot && cmp(h[i + 1], h[i]))
            ++i;
        if (cmp(h[i], h[k]))
        {
            swap(h[i], h[k]);
            k = i;
        }
        else
            break;
    }
    return ans;
}
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", op);
        if (op[0] == 'a')
        {
            scanf("%d%d", &x, &y);
            push(x, y);
        }
        else
        {
            Num n2 = pop();
            printf("%d %d\n", n2.x, n2.y);
        }
    }
    return 0;
}
