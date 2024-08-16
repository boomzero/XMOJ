#include <bits/stdc++.h>
#include <string>
using namespace std;

string s;
char a[2010];
int n,n1;

int main(int argc, const char* argv[])
{


scanf("%s", a);
cin>>n;
 long scout = strlen(a);

n1 = n % scout;
for(int i=0;i<n1;i++)
 {
 a[strlen(a)]=a[i];
 }
    //a[strlen(a)] = '\n';
   // cout << a << endl;
for(int i=0;i<scout;i++)
 {
 cout<<a[n1+i];
 }

 return 0;
}

