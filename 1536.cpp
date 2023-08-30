#include <bits/stdc++.h>
using namespace std;
double sta[1000010];
int top;
char str[105];
int main()
{
    while (cin >> str)
    {
        if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
        {
            double y = sta[--top];
            double x = sta[--top];
            switch (str[0])
            {
            case '+':
                sta[top++] = x + y;
                break;
            case '-':
                sta[top++] = x - y;
                break;
            case '*':
                sta[top++] = x * y;
                break;
            case '/':
                sta[top++] = x / y;
                break;
            default:
                assert(false);
            }
        }
        else
            sta[top++] = atof(str);
    }
    cout << setprecision(6) << fixed << sta[top - 1] << endl;
    return 0;
}
