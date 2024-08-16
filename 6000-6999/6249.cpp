#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)  
#define read(x) scanf("%d",&x); 
int n,m,x,y,xx,yy,aa[2001][2001]={0},bb[2001][2001]={0},a,b;
int main()
{
    read(n);read(m);
    For(i,n) For(j,n)
    {
         read(a);
         aa[i][j]=aa[i-1][j]+a;
    }
    For(i,n) For(j,n)
        {
          read(b);
          bb[i][j]=bb[i][j-1]+b;
        }
     For(i,m)
       {
         read(x);read(y);read(xx);read(yy);
         long long ans=0;
         if (x>xx) swap(x,xx);
         if (y>yy) swap(y,yy); 
         For(j,n)
           ans+=(long long)(aa[xx][j]-aa[x-1][j])*(long long)(bb[j][yy]-bb[j][y-1]);
         printf("%lld\n",ans);
       }
}
