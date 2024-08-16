#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int t,n,a[MAXN],q1[MAXN][2],q2[MAXN][2],l1,l2,r1,r2,ans;
struct node{
	int flag,sum,id;
};
namespace IO{
	inline int read(){
		int sum=0;char ch=getchar();
		while(ch<'0'||ch>'9') ch=getchar();
		while(ch>='0'&&ch<='9') {sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
		return sum;
	}
}
using namespace IO;
namespace  Get_Ans{
	node Get_Max(){
		int sum=0,flag=1,id=0;
		if(l2<=r2){
			if(q2[r2][0]>=sum){
				sum=q2[r2][0],id=q2[r2][1],flag=2;
			}
		}
		if(l1<=r1){
			if(q1[r1][0]>sum){
				sum=q1[r1][0],id=q1[r1][1],flag=1;
			}
			else if(q1[r1][0]==sum&&q1[r1][1]>id){
				sum=q1[r1][0],id=q1[r1][1],flag=1;
			}
		}
		if(flag==1)
			r1--;
		else
			r2--;
		return (node){flag,sum,id};
	}
	node Get_Min(){
		int sum=0x7f7f7f7f,flag=1,id=0;
		if(l2<=r2){
			if(q2[l2][0]<=sum){
				sum=q2[l2][0],id=q2[l2][1],flag=2;
			}
		}
		if(l1<=r1){
			if(q1[l1][0]<sum){
				sum=q1[l1][0],id=q1[l1][1],flag=1;
			}
			else if(q1[l1][0]==sum&&q1[l1][1]<id){
				sum=q1[l1][0],id=q1[l1][1],flag=1;
			}
		}
		if(flag==1)
			l1++;
		else
			l2++;
		return (node){flag,sum,id};
	}
	void Solve1(){
		while(1){
			if(n-ans==1) return ;
			node x=Get_Max(),y=Get_Min();
			node z=Get_Min();
			if(x.sum-y.sum>z.sum||(x.sum-y.sum==z.sum&&x.id>z.id)){
				ans++;
				q2[--l2][0]=x.sum-y.sum;q2[l2][1]=x.id;
				if(l1<=r1&&(z.sum<q1[l1][0]||(z.sum==q1[l1][0]&&z.id<q1[l1][1]))){
					q1[--l1][0]=z.sum,q1[l1][1]=z.id;
				}
				else{
					q2[--l2][0]=z.sum,q2[l2][1]=z.id;
				}
				continue;
			}
			else{
				if(x.flag==1){
					q1[++r1][0]=x.sum,q1[r1][1]=x.id;
				}
				else{
					q2[++r2][0]=x.sum,q2[r2][1]=x.id;
				}
				if(z.flag==1){
					q1[--l1][0]=z.sum,q1[l1][1]=z.id;
				}
				else{
					q2[--l2][0]=z.sum,q2[l2][1]=z.id;
				}
				if(y.flag==1){
					q1[--l1][0]=y.sum,q1[l1][1]=y.id;
				}
				else{
					q2[--l2][0]=y.sum,q2[l2][1]=y.id;
				}
				return ;
			}
		}
	}
	bool Slove2(int last){
		if(last==0)
			return 0;
		if(last==1)
			return 0;
		if(last==2)
			return 1;
		node x=Get_Max(),y=Get_Min(),z=Get_Min();
		if(x.sum-y.sum>z.sum||(x.sum-y.sum==z.sum&&x.id>z.id))
			return 1;
		else{
			if(l1<=r1&&(z.sum<q1[l1][0]||(z.sum==q1[l1][1]&&q1[l1][1]>z.id))){
				q1[--l1][0]=z.sum,q1[l1][1]=z.id;
			}
			else{
				q2[--l2][0]=z.sum,q2[l2][1]=z.id;
			}
			if(l1<=r1&&(x.sum-y.sum<q1[l1][0]||(x.sum-y.sum==q1[l1][0]&&q1[l1][1]>x.id))){
				q1[--l1][0]=x.sum-y.sum,q1[l1][1]=x.id;
			}
			else{
				q2[--l2][0]=x.sum-y.sum,q2[l2][1]=x.id;
			}
			return !Slove2(last-1);
		}
	}
}
using namespace Get_Ans;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=read();
	bool flag=0;
	while(t--){
		ans=0;
		memset(q1,0,sizeof(q1));
		memset(q2,0,sizeof(q2));
		if(!flag){
			n=read();flag=1;
			for(int i=1;i<=n;i++)
				a[i]=read();
		}
		else{
			int k=read();
			for(int i=1;i<=k;i++){
				int x,y;
				x=read(),y=read();
				a[x]=y;
			}
		}
		l1=1,r1=0,l2=n+1,r2=n;
		for(int i=1;i<=n;i++)
			q1[++r1][0]=a[i];
		for(int i=1;i<=n;i++)
			q1[i][1]=i;
		Solve1();
		if(Slove2(n-ans))
			ans++;
		printf("%d\n",n-ans);
	}
	return 0;
}
