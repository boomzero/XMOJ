#include<bits/stdc++.h>
using namespace std;
int n,sx,sy,ex,ey,px[10][10],py[10][10],que[100],h,t,top;
char ans[100];
int a[10][10][10][10],vis[10][10];
int dx[4]= {1,-1,0,0},dy[4]= {0,0,-1,1};
int hash(int x,int y) {
    return x*1000+y;
}
void unhash(int v,int &x,int &y) {
    x=v/1000;
    y=v%1000;
}
void print() {
    int x=ex,y=ey;
    while(x!=sx||y!=sy) {
        if (px[x][y]<x) ans[top++]='E';
        if (px[x][y]>x) ans[top++]='W';
        if (py[x][y]<y) ans[top++]='S';
        if (py[x][y]>y) ans[top++]='N';
        int x2=px[x][y];
        y=py[x][y];
        x=x2;
    }
    while (top)
        printf("%c",ans[--top]);
    printf("\n");
}
void bfs() {
    memset(vis,0,sizeof(vis));
    que[t++]=sx*1000+sy;
    vis[sx][sy]=1;
    while (h<t) {
        int p=que[h++],x=p/1000,y=p%1000;
        if (x==ex&&y==ey) {
            print();
            break;
        }
        for (int i=0; i<4; ++i) {
            int x2=x+dx[i],y2=y+dy[i];
            if (!a[x][y][x2][y2]&&!vis[x2][y2]) {
                vis[x2][y2]=1;
                que[t++]=x2*1000+y2;
                px[x2][y2]=x;
                py[x2][y2]=y;
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    for (int i=1; i<=3; ++i) {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1==x2)
            for (int j=y1+1; j<=y2; ++j)
                a[x1][j][x1+1][j]=a[x1+1][j][x1][j]=1;
        else
            for (int j=x1+1; j<=x2; ++j)
                a[j][y1][j][y1+1]=a[j][y1+1][j][y1]=1;
    }
    for (int i=1; i<=6; ++i) {
        a[1][i][0][i]=a[0][i][1][i]=a[i][1][i][0]=a[i][0][i][1]=1;
        a[6][i][7][i]=a[7][i][100][i]=a[i][6][i][7]=a[i][7][i][6]=1;
    }
    bfs();
    return 0;
}
//migong
