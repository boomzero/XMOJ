#include <stdio.h>
#include <string.h>
char input[100 + 10];
int islow(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}
int isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
int main()
{
    int p1, p2, p3;
    int i, j, k, len, len2;
    scanf("%d%d%d", &p1, &p2, &p3);
    scanf("%s", input);
    len = strlen(input);
    printf("%c", input[0]);
    for (i = 1; i < len; i++)
    {
        if (input[i] == '-' && i + 1 < len)
        {
            if (islow(input[i - 1]) && islow(input[i + 1]))
            {
                if (input[i + 1] - input[i - 1] == 1)
                {
                }
                else if (input[i + 1] <= input[i - 1])
                {
                    printf("%c", input[i]);
                }
                else
                {
                    if (p1 == 3)
                    {
                        len2 = (input[i + 1] - input[i - 1] - 1) * p2;
                        for (j = 0; j < len2; j++)
                            printf("*");
                    }
                    else if (p1 == 1)
                    {
                        len2 = input[i + 1] - input[i - 1] - 1;
                        if (p3 == 1)
                        {
                            for (j = 1; j <= len2; j++)
                                for (k = 1; k <= p2; k++)
                                    printf("%c", input[i - 1] + j);
                        }
                        else if (p3 == 2)
                        {
                            for (j = len2; j >= 1; j--)
                                for (k = 1; k <= p2; k++)
                                    printf("%c", input[i - 1] + j);
                        }
                    }
                    else if (p1 == 2)
                    {
                        len2 = input[i + 1] - input[i - 1] - 1;
                        if (p3 == 1)
                        {
                            for (j = 1; j <= len2; j++)
                                for (k = 1; k <= p2; k++)
                                    printf("%c", input[i - 1] - 'a' + 'A' + j);
                        }
                        else if (p3 == 2)
                        {
                            for (j = len2; j >= 1; j--)
                                for (k = 1; k <= p2; k++)
                                    printf("%c", input[i - 1] - 'a' + 'A' + j);
                        }
                    }
                }
            }
            else if (isnum(input[i - 1]) && isnum(input[i + 1]))
            {
                if (input[i + 1] - input[i - 1] == 1)
                {
                }
                else if (input[i + 1] <= input[i - 1])
                {
                    printf("%c", input[i]);
                }
                else
                {
                    if (p1 == 3)
                    {
                        len2 = (input[i + 1] - input[i - 1] - 1) * p2;
                        for (j = 0; j < len2; j++)
                            printf("*");
                    }
                    else if (p3 == 1)
                    {
                        len2 = input[i + 1] - input[i - 1] - 1;
                        for (j = 1; j <= len2; j++)
                            for (k = 1; k <= p2; k++)
                                printf("%c", input[i - 1] + j);
                    }
                    else if (p3 == 2)
                    {
                        len2 = input[i + 1] - input[i - 1] - 1;
                        for (j = len2; j >= 1; j--)
                            for (k = 1; k <= p2; k++)
                                printf("%c", input[i - 1] + j);
                    }
                }
            }
            else
            {
                printf("%c", input[i]);
            }
        }
        else
            printf("%c", input[i]);
    }
    return 0;
}
