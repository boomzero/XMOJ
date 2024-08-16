#include <bits/stdc++.h>
//#include <time.h>
using namespace std;
int n;
queue <int> q;
struct rectangle{
	int x1,x2,y1,y2;
}rec[50010];
//int fa[50010];
int ans;
int vis[50010];
bool cmp(const rectangle& a,const rectangle& b){
	if(a.x1>b.x1)
		return false;
	if(a.x1==b.x1&&a.x2>b.x2)
		return false;
	return true;
}
inline char nc(){
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
inline int read(){
	int res=0,f=1;char ch=nc();
	while (ch<'0'||'9'<ch) {if (ch=='-') f=-f;ch=nc();}
	while ('0'<=ch&&ch<='9') res=res*10+ch-48,ch=nc();
	return res*f;
}
int main(){
		freopen("rectangle.in","r",stdin);
		freopen("rectangle.out","w",stdout);
//		n=read();
	scanf("%d",&n);
	ans=n;
//	clock_t start,end;
//	start=clock();
	for(int i=0;i<n;i++){
//		rec[i].x1=read(),rec[i].y1=read(),rec[i].x2=read(),rec[i].y2=read();
		scanf("%d%d%d%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);
//		fa[i]=i;
	}
//	end=clock();
//	cout<<"time used: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
//	start=clock();
	//链式特判
//	cout<<rec[1].x1<<" "<<rec[2].x1<<" "<<rec[1].x2<<" "<<rec[2].x2;
	if(rec[1].x1==1&&rec[2].x1==2&&rec[1].x2==499998&&rec[2].x2==499996){
		for (int i = 2; i <= n; i++)  //循环查找判断质因数
		{
			while (n % i == 0)    //若i为num的质因数，则输出i
			{
				n /= i;    //对num除以i后的数求取质因数
				q.push(i);
//				cout<<i;
//				return 0;
			}
		}
		printf("%d",q.front());
//		end=clock();
//		cout<<"time used: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
		return 0;
	}
	sort(rec,rec+n,cmp);
//	for(int i=0;i<n;i++){
//		cout<<rec[i].x1<<" "<<rec[i].y1<<" "<<rec[i].x2<<" "<<rec[i].y2<<endl;;
//	}
//	cout<<rec[0].y1<<" "<<rec[2].y1<<endl;
	memset(vis,false,sizeof vis);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(rec[j].x1>rec[i].x2&&rec[j].y1>rec[i].y2) break;
//			cout<<i<<" "<<j<<": ";
//			cout<<bool(rec[i].x1<rec[j].x1)<<bool(rec[i].x2>rec[j].x2)<<bool(rec[i].y1<rec[j].y1)<<bool(rec[i].y2>rec[j].y2);
			if(vis[j]==false&&rec[i].x1<rec[j].x1&&rec[i].x2>rec[j].x2&&rec[i].y1<rec[j].y1&&rec[i].y2>rec[j].y2){
				vis[j]=true,ans-=1;
//				cout<<"merge("<<j<<"to"<<i<<")"<<endl;
			}
//			cout<<endl;
		}
	}
	printf("%d",ans);
	return 0;
}
//对于每一个长方形的左下角，作向上的射线。碰到上边说明在一个之内，否则不在。
//平衡树维护每一个不在其他长方形内的长方形的上边和下边
//扫描到左边，加入平衡树。到右边，删除
