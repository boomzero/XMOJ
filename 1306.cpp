#include <bits/stdc++.h>

using namespace std;

char t[110];

string s1, s2, sx, s3, sy;

int pos, len;

int main()
{

	fgets(t, 110, stdin);

	len = strlen(t);

	while (t[len - 1] == '\r' || t[len - 1] == '\n')
		t[--len] = '\0';

	s1 = s1 + " " + t + " ";

	cin >> sx;

	s2 += " ";

	s2 += sx;

	s2 += " ";

	cin >> sy;

	s3 += " ";

	s3 += sy;

	s3 += " ";

	//	cout<<"s1:"<<s1<<"::end"<<s2<<"::"<<s3<<"::end"<<endl;

	string::size_type pos = s1.find(s2, 0);

	while (pos != string::npos)
	{

		s1 = s1.substr(0, pos) + s3 + s1.substr(pos + s2.length());

		pos = s1.find(s2, 0);
	}

	int len = s1.size();

	s1 = s1.substr(1, len - 1 - 1);

	cout << s1;

	return 0;
}
