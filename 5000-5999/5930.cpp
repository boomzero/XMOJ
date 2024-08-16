#include<cstdio>
const int N=1010,T=40;
const int dx[]={1,0,0,-1},dy[]={0,1,-1,0},d[]={69,78,83,87};
int n,m,k,i,j,s,t,x[N],y[N],p[N],q[N],g[T*2][T*2],f[T][T*2][T*2],u,v;
int max(int x,int y){return x>y?x:y;}
int abs(int x){return x>0?x:-x;}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<n;i++)
		scanf("%d%d",x+i,y+i);
	for(i=0;i<m;i++)
		scanf("%d%d",p+i,q+i);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(abs(p[j]-x[i])+abs(q[j]-y[i])<=k)
				g[p[j]-x[i]+T][q[j]-y[i]+T]++;
	for(t=k;t>=0;t--){
		for(u=T-t;u<=T+t;u++){
			for(v=T-t;v<=T+t;v++){
				for(i=0;i<4;i++)
					f[t][u][v]=max(f[t+1][u+dx[i]][v+dy[i]],f[t][u][v]);
				f[t][u][v]+=g[u][v];
			}
		}
	}
	printf("%d\n",f[0][T][T]);
	u=T;v=T;
	for(i=0;i<k;i++){
		for(j=0;j<4;j++)
			if(f[i][u][v]==f[i+1][u+dx[j]][v+dy[j]]+g[u][v])
				break;
		u+=dx[j];v+=dy[j];
		printf("%c",d[j]);
	}
	return 0;
}
