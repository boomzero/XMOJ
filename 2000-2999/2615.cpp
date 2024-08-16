#include <bits/stdc++.h>
using namespace std;
int n,a[210];
//	n=the number of students/2
//	a[i]=the grades of the students

int main(){
    cin>>n;
    for(int i=0;i<2*n;++i)
        cin>>a[i];
    for(int i=2*n-1;i>0;--i)
        for(int j=0;j<i;++j)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
    if(a[n]>a[n-1])
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
