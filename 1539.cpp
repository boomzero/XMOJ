#include <bits/stdc++.h>

using namespace std;

int top1, n, sta[110];

char str[10];

bool is_empty1()
{

	return top1 == 0;
}

void push(int x)
{ // 假设栈不满

	sta[top1++] = x;
}

int pop()
{ // 假设栈不为空

	return sta[--top1];
}

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> str;

		if (str[0] == 'P' && str[1] == 'U')
		{

			int x;

			cin >> x;

			push(x);
		}

		else
		{

			if (is_empty1() == true)
			{

				cout << "error" << endl;
			}

			else
			{

				cout << pop() << endl;
			}
		}
	}

	for (int i = top1; i--; i >= 0)
	{

		cout << sta[i] << " ";
	}

	if (top1 == 0)

		cout << "empty";

	return 0;
}
