#include <iostream>
#include <cstdio>
using namespace std;
double v;
double r;
int main(void)
{
	std::cin >> r;
	v = 4 * 3.14 * r * r * r / 3;
	printf("%.2f", v);
	return 0;
}
