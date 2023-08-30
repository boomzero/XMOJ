#include <bits/stdc++.h>
using namespace std;
int n, t[510], m, w[510];
bool f[510];
void bubble()
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (w[j] < w[j + 1])
			{
				swap(t[j], t[j + 1]);
				swap(w[j], w[j + 1]);
			}
		}
	}
}
void test()
{
	for (int i = 0; i < n; i++)
	{
		cout << f[i] << " ";
	}
	cout << endl;
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	bubble();
	for (int i = 0; i < n; i++)
	{
		bool f1 = false;
		for (int j = t[i] - 1; j >= 0; j--)
		{
			if (f[j] == false)
			{
				f[j] = true;
				f1 = true;
				break;
			}
		}
		if (f1 == false)
		{
			for (int j = n - 1; j >= t[i]; j++)
			{
				if (f[j] == false)
				{
					f[j] = true;
					m -= w[i];
					//			  		cout<<"-"<<w[i]<<endl;
					break;
				}
			}
		}
		//		test();
	}
	//		else{
	//			bool f1=false;
	//			for(int j=t[i]-1;j>=0;j--){
	//				if(f[j-1]==false){
	//					f[j-1]=true;
	//					f1=true;
	//					break;
	//				}
	//			}
	//			if(f1==false){
	//				for(int j=t[i]+1;j<n;j++){
	//					if(f[j-1]==false){
	//						f[j-1]=true;
	//				  		m-=w[i];
	//						break;
	//					}
	//				}
	//				test();
	//			}
	//		}
	//	}
	//	cout<<"last"<<endl;
	//	for(int i=0;i<n;i++){
	//		cout<<f[i]<<" ";
	//	}
	//	cout<<endl;
	cout << m;
	return 0;
}
// 	先按照扣分顺序从大到小排序
//	尽量排在时间限制前，且尽量往后放
