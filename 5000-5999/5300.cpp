#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string k, c, m;
	cin >> k >> c;
	m = c;
	int len = k.size();
	for (int i=0; i<len; ++i)
		k[i] = toupper(k[i]);
	for (int i=0; i<c.size(); ++i) {
		m[i] = (c[i]>='a')?'a':'A';
		c[i] = toupper(c[i]);
		m[i] += (c[i] - k[i%len] + 26) % 26;
	}
	cout << m << endl;
	return 0;
}
