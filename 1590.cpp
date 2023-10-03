#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 105;
struct NODE
{
    char str[N];
    int count;
};
int LengthB = 0;
struct NODE b[60000];
void check(char temp[])
{
    int i;
    if (LengthB == 0)
    {
        strcpy(b[0].str, temp);
        b[0].count = 1;
        LengthB++;
        return;
    }
    for (i = 0; i < LengthB; i++)
    {
        if (strcmp(b[i].str, temp) == 0)
        {
            b[i].count++;
            return;
        }
    }
    strcpy(b[LengthB].str, temp);
    b[LengthB].count = 1;
    LengthB++;
}
int cmp(const void *a, const void *b)
{
    struct NODE x, y;
    x = *(struct NODE *)a;
    y = *(struct NODE *)b;
    return strcmp(x.str, y.str);
}
int main(int argc, char *argv[])
{
    char a[N], temp[N];
    int i, j, len, k, t;
    scanf("%s", a);
    len = strlen(a);
    for (i = 0; i < len; i++)
    {
        k = 0;
        for (j = i; j < len; j++)
        {
            temp[k] = a[j];
            k++;
            temp[k] = '\0';
            check(temp);
        }
    }
    qsort(b, LengthB, sizeof(b[0]), cmp);
    for (i = 0; i < LengthB; i++)
    {
        if (b[i].count > 1)
            printf("%s %d\n", b[i].str, b[i].count);
    }
    return 0;
}
