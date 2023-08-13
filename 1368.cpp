/*
一个字符串 $S$ 的 “子序列”，是指将 $S$ 的若干个（也可能零个）字符删除后，不改变先后次序，重新拼接成的字符串。
例如："arc"、"artistic" 和空串都是字符串 "artistic" 的子序列，但 "abc" 和 "ci" 不是。
现在给定一个由小写字母构成的字符串 $A$，请输出由小写字母构成，且不是 $A$ 的子序列的最短字符串。如果存在多个字符串满足条件，则输出字典序最小的那个。

一行，一个由小写英文字母构成的字符串 $A$。

由小写字母构成且不是 $A$ 的子序列的最短字符串。如果有多个字符串满足条件，输出字典序最小的那个。
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;
    string ans = "";
    for (char c = 'a'; c <= 'z'; c++)
    {
        bool found = false;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == c)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            string new_ans = ans + c;
            bool is_subseq = true;
            int j = 0;
            for (int i = 0; i < A.size(); i++)
            {
                if (j < new_ans.size() && A[i] == new_ans[j])
                {
                    j++;
                }
            }
            if (j == new_ans.size())
            {
                ans = new_ans;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
