#include <bits/stdc++.h>

const int N = 1e5 + 7;

#define R12() ((rand() << 12) + (rand() << 7) + rand())

#define R233() (R12() % 4454515 + R12() % 45444211 + R12() % 144521 + 1)

int Q, min1, w;

class Treap
{

private:
	struct Node
	{

		Node *son[2];

		int size, num, data, hr;

		Node() {}

		Node(int data, Node *fl) : data(data)
		{
			son[0] = son[1] = fl;
			size = num = 1;
			hr = R233();
		}

		void update() { size = son[0]->size + son[1]->size + num; }

	} *Null, *root, meme[N], *pool;

	int ball, money;

	void rotate(Node *&T, bool v)
	{

		Node *Tt = T->son[v];

		T->son[v] = Tt->son[v ^ 1];

		Tt->son[v ^ 1] = T;

		T->update();
		Tt->update();

		T = Tt;
	}

	void Delete(Node *&T)
	{

		if (T == Null)
			return;

		while (T->son[1] != Null && T->data + money <= min1)
			T->son[0] = Null, rotate(T, 1);

		if (T->data + money <= min1)
		{

			if (T->data + money < min1)
				T = Null;

			else
				T->son[0] = Null, T->size = T->num;

			return;
		}

		Delete(T->son[0]);

		T->update();
	}

	void Insert(Node *&T)
	{

		if (T == Null)
		{
			T = new (pool++) Node(ball, Null);
			return;
		}

		if (T->data == ball)
		{
			++T->num;
			++T->size;
			return;
		}

		bool v = T->data < ball;

		Insert(T->son[v]);

		if (T->hr < T->son[v]->hr)
			rotate(T, v);

		else
			T->update();
	}

	int Rank(Node *&T)
	{

		if (T == Null)
			return -1;

		if (T->son[1]->size >= ball)
			return Rank(T->son[1]);

		if (T->son[1]->size + T->num >= ball)
			return T->data;

		ball -= T->son[1]->size + T->num;
		return Rank(T->son[0]);
	}

public:
	Treap()
	{
		Null = new Node();
		Null->size = Null->num = 0;
	}

	void clear()
	{
		root = Null;
		pool = meme;
		money = 0;
	}

	void Ins(int num)
	{
		ball = num - money;
		Insert(root);
	}

	void Rai(int num) { money += num; }

	void Cut(int num)
	{
		money -= num;
		Delete(root);
	}

	int Ran(int num)
	{
		ball = num;
		int k = Rank(root);
		return k == -1 ? -1 : k + money;
	}

	int size() { return root->size; }

} treap;

int ans;

char opt[10];

int main()
{

	scanf("%d%d", &Q, &min1);

	treap.clear();

	while (Q--)
	{

		scanf("%s%d", opt, &w);

		if (opt[0] == 'I' && w >= min1)
		{

			treap.Ins(w);

			++ans;
		}

		if (opt[0] == 'A')
			treap.Rai(w);

		if (opt[0] == 'S')
			treap.Cut(w);

		if (opt[0] == 'F')
			printf("%d\n", treap.Ran(w));
	}

	printf("%d\n", ans - treap.size());

	return 0;
}
