#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,f,x,y;
char a[2010][2010];
void read(int &x){
    char ch=getchar();x=0;
    while(!(ch>='0'&&ch<='9'))
    	ch=getchar();
    while((ch>='0'&&ch<='9'))
    	x=x*10+ch-'0',ch=getchar();
}
int main(){
    read(n);
    read(m);
    read(f);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        	a[i][j]=i&1?'D':'G';
    for(int i=1;i<=n;i++){
        if(i<n)
        	a[i][1]='P';
        if(i>1&&(i&1))
        	a[i][2]='L';
        if(!(i&1))
        	a[i][m]='L';
    }
    for(int i=1;i<=f;i++){
        read(x);read(y);
        if(x&1){
        	a[x+1][y-1]='L';
        	a[x][y+2]='P';
        	a[x+1][y+2]='P';
        	a[x+2][y+3]='L';
        }
        else{
            if(y==3){
            	a[x][1]='G';
            	a[x][2]='P';
            	a[x+1][2]='D';
            	a[x+1][y+2]='L';
            }
            else{
            	a[x+1][y+2]='L';
            	a[x][y-1]='P';
            	a[x+1][y-1]='P';
            	a[x+2][y-2]='L';
            }
        }
    }
    puts("TAK");
    x=1;y=1;
    for(int i=1;i<=n*m-4*f;i++){
        putchar(a[x][y]);
        if(a[x][y]=='L')
        	x--;
        else if(a[x][y]=='P')
        	x++;
        else if(a[x][y]=='D')
        	y--;
        else if(a[x][y]=='G')
        	y++;
    }
    return 0;
}
