#include<iostream>
using namespace std;
struct wj {
	int num = 0;
	string name;
}nm[100010];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> nm[i].num >> nm[i].name;
	}
	int i = 0;
	for (int j = 0; j < m; j++) {
		int a, b;
		cin >> a >> b;
		if (nm[i].num == 0 && a == 1)
			i = (i + b) % n;
		else if (nm[i].num == 1 && a == 0)
			i = (i + b) % n;
		else if (nm[i].num == 0 && a == 0)
			i = (i + n - b) % n;
		else if (nm[i].num == 1 && a == 1)
			i = (i + n - b) % n;
	}
	cout << nm[i].name;
	return 0;
}
