/*
读书节来了，学校里采购了一批书发给学生。小明班级一共有 $N$ 个学生，第 $i$ 个学生分到了 $a_i$ 本书。由于有的同学书多，有的同学书少，大家都不是很满意。老师让小明帮忙做一些调整，尽量让每个人分到的书的数量相同。
小明想了一个办法，他每次会按顺序执行以下操作：
1. 找到拿到书最多的那个学生，从他那里拿走一本书。如果多于一个学生拿到的书一样多，则随机选择一个学生。
2. 找到拿到书最少的那个学生，将刚刚拿走的书给这个学生。如果多于一个学生拿到的书一样多，则随机选择一个。注意，找书最少的学生的时候，是包含刚刚被拿走一本书的那个学生的。
现在，小明想请你帮他计算，$K$ 次操作后，最终拿到最多书的学生和拿到最少书的学生，他们手里的书的数量差是多少。

输入包含多组测试数据。
第一行一个正整数 $T$，表示测试数据的组数。
对于每组测试数据，第一行包含两个正整数 $N$ 和 $K$，表示学生人数和操作次数；第二行 $N$ 个正整数 $a_1,a_2,...,a_N$，表示每个学生初始时的拿到的书的数量。

每组测试数据输出一行，一个整数，表示答案。

$1 \le T \le 10$，$1 \le N \le 10^5$，$1 \le K \le 10^{15}$，$1 \le a_i \le 10^9$。

当 $K$ 很大时，每位同学的书的数量会趋近相同，最多与最少相差为 $0$ 或 $1$。分别二分计算出 $K$ 次操作能将初始书的数量 $\le L$ 的学生变成数量相同的书，初始书的数量 $\ge R$ 的学生变成数量相同的书。如果 $L \ge R$，则若总数能整除人数输出 0 ，否则输出 1；否则，答案是 $R-L$。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100'005;
ll t, n, k, a[N];
int main()
{
    scanf("%lld", &t);
    while (t-- > 0)
    {
        scanf("%lld%lld", &n, &k);
        ll sum = 0, minn = 1e9, maxx = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            sum += a[i];
            minn = min(minn, a[i]);
            maxx = max(maxx, a[i]);
        }
        if (k >= sum)
        {
            printf("0\n");
            continue;
        }
        ll l = minn, r = maxx;
        while (l < r)
        {
            ll mid = (l + r) >> 1;
            ll cnt = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] <= mid)
                    cnt += mid - a[i];
            if (cnt <= k)
                l = mid + 1;
            else
                r = mid;
        }
        ll L = l;
        l = minn, r = maxx;
        while (l < r)
        {
            ll mid = (l + r + 1) >> 1;
            ll cnt = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] >= mid)
                    cnt += a[i] - mid;
            if (cnt <= k)
                r = mid - 1;
            else
                l = mid;
        }
        ll R = l;
        if (L >= R)
        {
            if (sum % n == 0)
                printf("0\n");
            else
                printf("1\n");
        }
        else
            printf("%lld\n", R - L);
    }
    return 0;
}
