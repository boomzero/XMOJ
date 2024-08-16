#include <stdio.h>
struct room
{
    int haveStairs;
    int x;
};
int N,M,Y;
struct room a[10002][102];
int count[100002]={0};
int ans=0;
int main()
{
    int i,j,t,k;

    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            scanf("%d%d",&a[i][j].haveStairs,&a[i][j].x);
            count[i]+=a[i][j].haveStairs;
        }
    }
    scanf("%d",&Y);

    for(i=0;i<N;i++)
    {
        t=a[i][Y].x;
        ans=(ans+t)%20123;
        t=t%count[i];
        if(t==0) t=count[i];

        k=Y;
        do
        {
            if(a[i][k].haveStairs==1) t--;
            k++;
            k=k%M;
        }while(t);
        k--;
        if(k==-1) k=M-1;
        Y=k;
    }
    printf("%d\n",ans);
    return 0;
}
