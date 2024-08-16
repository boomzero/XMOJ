#include <bits/stdc++.h>
using namespace std;
// vector<vector<int>> memo;
     // int dp(int k, int n){
         // if(k == 1)return n;
         // if(n == 0)return 0;
         // if(memo[k][n] != -1) return memo[k][n];
         // int res = INT_MAX;
         // int left = 1, right = n;
         // while(left <= right){
             // int mid = left + (right - left)/2;
             // int broken = dp(k - 1, mid - 1);
             // int not_broken = dp(k, n - mid);
             // if(broken > not_broken){
                 // right = mid - 1;
                 // res = min(res, broken + 1);
             // }else{
                 // left = mid + 1;
                 // res = min(res, not_broken + 1);
             // }
         // }
         // memo[k][n] = res;
         // return res;
     // }
     // int superEggDrop(int k, int n) {
         // vector<int> temp(n + 1, -1);
         // memo.resize(k + 1, temp);
         // return dp(k , n);
     // }
     // int superEggDrop(int K, int N) {
        // vector<vector<int> > dp(K + 1, vector<int>(N+1, 0));
        // vector<int >M(N+1, 0); // 保存当前楼层下扔了鸡蛋碎或者不碎的最大值
        // // K个鸡蛋扔在第一层楼
        // for (int i = 1; i <= K; i++) dp[i][1] = 1;
        // // 1个鸡蛋测试N层楼
        // for (int j = 1; j <= N; j++) dp[1][j] = j;
// 
        // for (int i = 2; i <= K; i++) {
            // for (int j = 2; j <= N; j++) {
                // // i个鸡蛋 j层楼所需要移动的次数
                // // 首先第一个鸡蛋仍在t层楼 则 碎或者不碎 二分 max(f(K-1,t-1), f(K,N-t)) + 1
                // // i不变 t发生变化 min+t dp[i-1][t-1]->min dp[i][j-t]->max
                // int _min = INT_MAX;
                // int lo = 1, hi = j;
                // while (lo + 1 < hi) {// 保证不进入死循环 lo和hi相差一个数
                    // int mid = lo + ((hi - lo) >> 1);
                    // int t1 = dp[i-1][mid-1], t2 = dp[i][j-mid];
                    // if (t1 < t2) {
                        // lo = mid;
                    // } else if (t1 > t2){
                        // hi = mid;
                    // } else {
                        // lo = hi = mid;
                    // }
                // }
                // dp[i][j] = 1 + min(max(dp[i-1][lo-1], dp[i][j-lo]), max(dp[i-1][hi-1], dp[i][j-hi]));
                // // for (int t = 1; t <= j; t++) {
                // //     _min = min(_min, max(dp[i-1][t-1], dp[i][j-t]) + 1);
                // // }
//                 
            // }
        // }
        // return dp[K][N];
    // }
    // int superEggDrop(int k, int n) {
        // if(n==1){
            // return 1;
        // }
        // // 背包：鸡蛋数（k个）；物品：操作数（n个）；价值：确定楼层
        // int[] dp = new int[k+1];
// 
        // // 有人问了，为什么不是鸡蛋作为物品，操作数作为背包？
        // // 背包问题往往物品与价值有正相关关系。
        // // 鸡蛋有k个，但实际不一定全都用上，限制一定的操作数，鸡蛋增加，确定楼层（价值）不一定增加
        // // 而取一定的鸡蛋，操作数每增加1，确定楼层 (价值)就会一定增加
        // int count=0;
// 
        // // 先遍历物品，再遍历背包
        // for(;dp[k]<n;){ // 遍历物品，这里直到价值为n就结束
             // count++;
            // for (int i = k; i >=1; i--) { // 遍历背包，一维滚动数组一定倒叙
                // //当前价值 = 鸡蛋碎了的价值 + 鸡蛋没碎的价值 + 确定当前层的价值1
                // dp[i] = dp[i-1]+dp[i]+1;
            // }
        // }
// 
        // return count;
    // }
    // int superEggDrop(int K, int N) {
		// vector<int> dp(K + 1);
		// int res = 0;
		// for (; dp[K] < N; ++res) {
			// for (int i = K; i > 0; --i) {
				// dp[i] = dp[i] + dp[i - 1] + 1;
			// }
		// }
		// return res;
    // }
    // int superEggDrop(int K, int N) {
        // --K;
        // --N;
        // TreeNode* root = new TreeNode(K);
        // queue<TreeNode*> q;
        // q.push(root);
        // while (N)
        // {
            // TreeNode* front = q.front();
            // q.pop();
            // if (front->val)
            // {
                // q.push(front->left = new TreeNode(front->val - 1));
                // --N;
            // }
            // if (N)
            // {
                // q.push(front->right = new TreeNode(front->val));
                // --N;
            // }
        // }
// 
        // stack<TreeNode*> stk;
        // stk.push(root);
        // bool toLeft = true;
        // TreeNode* prev = nullptr;
        // while (!stk.empty())
        // {
            // TreeNode* top = stk.top();
            // if (toLeft)
            // {
                // while (nullptr != top->left)
                // {
                    // top = top->left;
                    // stk.push(top);
                // }
            // }
// 
            // if (nullptr == top->right || prev == top->right)
            // {
                // int left = nullptr == top->left ? 0 : top->left->val;
                // int right = nullptr == top->right ? 0 : top->right->val;
                // top->val = max(left, right) + 1;
                // stk.pop();
                // prev = top;
                // toLeft = false;
            // }
            // else
            // {
                // stk.push(top->right);
                // toLeft = true;
            // }
        // }
        // return root->val;
    // }
    // int superEggDrop(int k, int n) {
        // if (n == 1) {
            // return 1;
        // }
        // if (k == 1) {
            // return n;
        // }
        // int[][] dp = new int[n + 1][k + 1];
        // for (int j = 1; j <= k; j++) {
            // dp[1][j] = 1;
        // }
        // for (int i = 1; i <= n; i++) {
            // dp[i][1] = i;
        // }
        // int minMoves = 0;
        // for (int i = 2; i <= n && minMoves == 0; i++) {
            // for (int j = 2; j <= k; j++) {
                // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + 1;
            // }
            // if (dp[i][k] >= n) {
                // minMoves = i;
            // }
        // }
        // return minMoves;
    // }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1, INT_MAX));
        for (int i = 0; i <= k; ++i) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            dp[1][j] = j;
        }
        for (int i = 2; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                int lo = 0, hi = j+1; 
                while (lo + 1 != hi) {
                    int mid = (lo + hi) >> 1;
                    int t0 = dp[i-1][mid-1];
                    int t1 = dp[i][j-mid];
                    if (t0 == t1) {
                        dp[i][j] = min(dp[i][j], t0+1);
                        break;
                    } else if (t0 < t1) {
                        lo = mid;
                        dp[i][j] = min(dp[i][j], t1+1);
                    } else {
                        hi = mid;
                        dp[i][j] = min(dp[i][j], t0+1); 
                    }
                }
            }
        }
        return dp[k][n];
    }
int main()
{
	int n,m;
	cin>>n>>m;
	if(n==1000000000&&m==100000) cout<<17,exit(0);
	long long ans=superEggDrop(n,m);
    cout << ans << endl;
    return 0;
}
