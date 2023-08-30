#include <bits/stdc++.h>

using namespace std;

int height[50010], n, vis[50010], dis[50010];

// bool judge(){

//	for(int i=0;i<n;i++){

//		if(vis[i]!=1) return false;

//	}

//	return true;

//}

int main()

{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {

        cin >> height[i];
    }

    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++)
    {

        if (i > 1 && height[i - 1] > height[i])
        {

            vis[i] = 1;

            continue;
        }

        if (i < n && height[i + 1] > height[i])
        {

            vis[i] = 1;

            continue;
        }

        cout << i << endl;
    }

    return 0;
}
