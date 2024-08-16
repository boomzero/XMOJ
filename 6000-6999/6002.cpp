#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("equation.in","r",stdin); freopen("equation.out","w",stdout);
    char c1,c2;
    int a,b;
    scanf("%c %c %d = %d",&c1,&c2,&b,&a);
    printf("%c %c %d = %d\n",c1,c2,b,a);
    switch(c2){
        case '+':
            printf("%c = %d - %d\n",c1,a,b);
            printf("%c = %d\n",c1,a-b);
            break;
        case '-':
            printf("%c = %d + %d\n",c1,a,b);
            printf("%c = %d\n",c1,a+b);
            break;
        case '*':
            printf("%c = %d / %d\n",c1,a,b);
            printf("%c = %d\n",c1,a/b);
            break;
        case '/':
            printf("%c = %d * %d\n",c1,a,b);
            printf("%c = %lld\n",c1,1ll*a*b);
            break;
    }
    return 0;
}


