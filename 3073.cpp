#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int n, Answer;
struct RECTANGLE
{
	int x1, y1, x2, y2;
	bool Removed;
};
vector<RECTANGLE> Rectangles;
int main()
{
//	freopen("rectangle.in", "r", stdin);
//	freopen("rectangle.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2; 
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		Rectangles.push_back((RECTANGLE){x1, y1, x2, y2});
	}
//	sort(Rectangles, Rectangles + n, 
//		[](RECTANGLE x, RECTANGLE y)
//		{
//			if (x.x1 != y.x1)
//				return x.x1 < y.x1;
//			else if (x.x2 != y.x2)
//				return x.x2 < y.x2;
//			else if (x.y1 != y.y1)
//				return x.y1 < y.y1;
//			return x.y2 < y.y2;
//		});
	for (int i = 0; i < n; i++)
		if (!Rectangles[i].Removed)
			for (int j = 0; j < n; j++)
				if (i != j && !Rectangles[j].Removed &&
					Rectangles[i].x1 <= Rectangles[j].x1 &&
					Rectangles[i].y1 <= Rectangles[j].y1 &&
					Rectangles[i].x2 >= Rectangles[j].x2 &&
					Rectangles[i].y2 >= Rectangles[j].y2)
				{
					Rectangles[j].Removed = true;
					Answer++;
				}
	printf("%d\n", Rectangles.size() - Answer);
	return 0;
}
