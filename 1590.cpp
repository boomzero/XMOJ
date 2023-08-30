#include <bits/stdc++.h>
struct objective
{
    char str[105];
    int count;
};
int lenb = 0;
struct objective b[60000];
void check(char temp[])
{
    int i;
    if (lenb == 0)
    {
        strcpy(b[0].str, temp);
        b[0].count = 1;
        lenb++;
        return;
    }
    for (i = 0; i < lenb; i++)
    {
        if (strcmp(b[i].str, temp) == 0)
        {
            b[i].count++;
            return;
        }
    }
    strcpy(b[lenb].str, temp);
    b[lenb].count = 1;
    lenb++;
}
int cmp(const void *a, const void *b)
{
    struct objective x, y;
    x = *(struct objective *)a;
    y = *(struct objective *)b;
    return strcmp(x.str, y.str);
}
int main(int argc, char *argv[])
{
    char a[105], temp[105];
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
    qsort(b, lenb, sizeof(b[0]), cmp);
    for (i = 0; i < lenb; i++)
    {
        if (b[i].count > 1)
            printf("%s %d\n", b[i].str, b[i].count);
    }
    return 0;
}
