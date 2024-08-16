#include <bits/stdc++.h>
using namespace std;
int cases = 0;
stack<char> p;
queue<char> q;
string s;
int advance(char ch);
void work();
void calcu();
int main()
{
    while (getline(cin, s, '\n'))
    {
        cases++;
        while (!q.empty())
            q.pop();
        while (!p.empty())
            p.pop();
        work();
        calcu();
        printf("%c\n", p.top());
    }
    return 0;
}
int advance(char ch)
{
    if (ch == '!')
        return 3;
    else if (ch == '&')
        return 2;
    else if (ch == '|')
        return 1;
    return 0;
}
void work()
{
    int length = s.size();
    for (int i = 0; i < length; i++)
    {
        char ch = s[i];
        if (ch != ' ')
        {
            if (ch == 'T' || ch == 'F')
                q.push(ch);
            else if (advance(ch))
            {
                if (p.empty())
                {
                    p.push(ch);
                    continue;
                }
                if (ch == '!' && p.top() == '!')
                {
                    p.pop();
                    continue;
                }
                while (!p.empty() && p.top() != '(' && advance(p.top()) >= advance(ch))
                {
                    q.push(p.top());
                    p.pop();
                }
                p.push(ch);
            }
            else if (ch == '(')
                p.push(ch);
            else if (ch == ')')
            {
                while (p.top() != '(')
                {
                    q.push(p.top());
                    p.pop();
                }
                p.pop();
            }
        }
    }
    while (!p.empty())
    {
        q.push(p.top());
        p.pop();
    }
    return;
}
void calcu()
{
    char a, b, c, ch;
    while (!q.empty())
    {
        ch = q.front();
        if (ch == '!')
        {
            int a = p.top();
            if (a != '!')
            {
                p.pop();
                p.push('T' + 'F' - a);
            }
        }
        else if (ch == '&')
        {
            a = p.top();
            p.pop();
            b = p.top();
            p.pop();
            if (b != a)
                p.push('F');
            else if (b == a)
                p.push(a);
            else
            {
                p.push(b);
                p.push(a);
            }
        }
        else if (ch == '|')
        {
            a = p.top();
            p.pop();
            b = p.top();
            p.pop();
            if (b != a)
                p.push('T');
            else if (b == a)
                p.push(a);
            else
            {
                p.push(b);
                p.push(a);
            }
        }
        else
            p.push(ch);
        q.pop();
    }
    return;
}
