#include <bits/stdc++.h>

using namespace std;

int top, len;

char sta[110];

void push(int x)
{ // 假设栈不满

	sta[top++] = x;
}

int pop()
{ // 假设栈不为空

	return sta[--top];
}

int main()
{

	cin >> sta;

	len = strlen(sta);

	for (int i = 0; i < len; i++)
	{

		if (sta[i] == '(')
		{

			push(i);
		}

		else if (sta[i] == ')')
		{

			cout << pop() << " " << i << endl;
		}
	}
}
