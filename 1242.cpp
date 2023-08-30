#include <bits/stdc++.h>

using namespace std;

int n;

string s1, s3;

int main()
{

	set<string> s;

	set<string>::iterator iter;

	//  getline(cin,s1);

	//  cout<<s1<<endl;

	while (cin >> s3)
	{

		s.insert(s3);
	}

	string s2;

	int tmp = 0, tmp2 = 0;

	//	for(int i=0;i<s1.size();i++){

	//		if(s1[i]!=' ') s2[tmp]=s1[tmp2];

	//		if(s1[i]==' '){

	//			s.insert(s2);

	//		}

	//	}

	for (iter = s.begin(); iter != s.end(); iter++)
	{

		printf("%s\n", (*iter).c_str());
	}
}
