//
//  main.cpp
//  -2
//
//  Created by Sean on 2020/2/25.
//  Copyright © 2020 Sean. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
int n, n1, n2, times;
int main(int argc, const char *argv[])
{
    scanf("%d", &n);
    n1 = n;
    int temp = 1;
    for (int i = 1; i <= n; i++)
    {
        if (temp < 10)
        {
            printf("%d", temp);
        }
        else if (temp >= 10)
        {
            temp = 0;
            printf("%d", temp);
        }
        temp++;
    }
    printf("\n");
    n2 = (4 * n - 4) % 10;
    printf("%d", n2);
    for (int i = 1; i <= n - 2; i++)
    {
        printf(" ");
    }
    n1 = temp;
    if (n1 >= 10)
    {
        n1 = 0;
    }
    if (n > 2)
        printf("%d\n", n1);
    else
        printf("3");
    if (n > 2)
    {
        for (int i = 1; i <= n - 3; i++)
        {
            if (n2 == 0)
            {
                n2 = 10;
            }
            printf("%d", n2 - 1);
            for (int j = 1; j <= n - 2; j++)
            {
                printf(" ");
            }
            n1 = n1 + 1;
            n2 = n2 - 1;
            if (n1 == 10)
            {
                n1 = 0;
            }
            printf("%d\n", n1);
        }
    }
    if (n > 2) /*if(n>2)
        {
            for(int i=1;i<=n;i++)
            {
                n2=n2-1;
                printf("%d",n2);
                if(n2==0)
                {
                    n2=10;
                }
            }
        }*/
    {
        for (int i = 1; i <= n; i++)
        {
            n2 = n2 - 1;
            if (n2 < 0)
            {
                n2 = 9;
            }
            printf("%d", n2);
        }
    }
    return 0;
}
/*
//  main.cpp
//  -2
//
//  Created by Sean on 2020/2/25.
//  Copyright © 2020 Sean. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
int n,n1,n2,times;
int main(int argc, const char * argv[]){
    scanf("%d",&n);
    n1=n;
    int temp=1;
    for (int i=1;i<=n;i++){
        if(temp<10)
        {
            printf("%d",temp);
        }
        else if(temp>=10)
        {
            temp=0;
            printf("%d",temp);
        }
        temp++;
    }
    printf("\n");
    n2=(4*n-4)%10;
    printf("%d",n2);
    for (int i=1;i<=n-2;i++){
        printf(" ");
    }
    n1=temp;
    if(n1>=10)
    {
        n1=0;
    }
    if(n>2)
    printf("%d\n",n1);
    else
        printf("3");
    if(n>2)
    {
        for (int i=1;i<=n-3;i++){
            if(n2==0)
            {
                n2=10;
            }
            printf("%d",n2-1);
            for(int j=1;j<=n-2;j++)
            {
                printf(" ");
            }
            n1=n1+1;
            n2=n2-1;
            if(n1==10)
            {
                n1=0;
            }
            printf("%d\n",n1);
        }
    }
    if(n>2)
    {
        for(int i=1;i<=n;i++)
        {
            n2=n2-1;
            printf("%d",n2);
            if(n2==0)
            {
                n2=10;
            }
        }
    }
    return 0;
}*/
