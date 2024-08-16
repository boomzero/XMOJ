#include <bits/stdc++.h>
char c[2][3];
int main()
{
    scanf("%s%s", c[0], c[1]);
    if (c[0][0] == c[1][2] &&
        c[0][1] == c[1][1] &&
        c[0][2] == c[1][0])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
