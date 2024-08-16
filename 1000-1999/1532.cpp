#include <bits/stdc++.h>
using namespace std;
int q[100010],front,rear,a[100010];
int n,k,p;
void push(int x)
{
    q[rear++]=x;
    if (rear==100000) rear=0;
}
int pop()
{
    int ret=q[front++];
    if (front==100000) front=0;
    return ret;
}
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    for (int i=1;i<=k;++i) push(i);
    for (int i=1;i<=k/n;++i) {
        for (int j=1;j<=n;++j) {
            int x=pop();
            if (j==n) a[i]=x;
            for (int s=1;s<=p;++s)
                push(pop());
        }
    }
    sort(a+1,a+k/n+1);
    for (int i=1;i<=k/n;++i)
        printf("%d\n",a[i]);
    return 0;
}
