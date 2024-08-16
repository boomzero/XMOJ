#include <bits/stdc++.h>
using namespace std;
int n,k;
long id[110];
double score[110];
int main() {
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>id[i]>>score[i];
    }
    for(int i=n;i>0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(score[j]<score[j+1])
            {
                swap(id[j], id[j+1]);
                swap(score[j], score[j+1]);
            }
        }
    }
    cout<<id[k-1]<<" "<<score[k-1];
    return 0;
}
