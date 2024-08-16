#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
struct segMMT{
	int left2,right2,y,f;
}a[N+N];
bool cmp(const segMMT&a,const segMMT&b){
	return a.y==b.y?a.f>b.f:a.y<b.y;
}
int n,m,ans,val_tot[N],y[N],val[N],tmp[N+N],k;
inline void swch45(int&val_tot,int&y){
	int tmpx=val_tot,tmpy=y;
	val_tot=tmpx+tmpy,y=tmpy-tmpx;
}//rotate for pi/4
struct segT{
	int bgmx[1<<19],lazy[1<<19];
	void rotate(int k){
		bgmx[k<<1]+=lazy[k];
		lazy[k<<1]+=lazy[k];
		bgmx[k<<1|1]+=lazy[k];
		lazy[k<<1|1]+=lazy[k];
		lazy[k]=0;
	}
	void insert(int left2,int right2,int a,int L,int R,int k){
		if(left2<=L&&R<=right2){
			bgmx[k]+=a;
			lazy[k]+=a;
			return;
		}
		rotate(k);
		if(left2<=(L+R>>1))
			insert(left2,right2,a,L,(L+R>>1),k<<1);
		if(right2>(L+R>>1))
			insert(left2,right2,a,(L+R>>1)+1,R,k<<1|1);
		bgmx[k]=max(bgmx[k<<1],bgmx[k<<1|1]);
	}
}t;//Maybe SegTree can work better that splay/Treap in this consequence?
int left2=0,right2=0;
int main(){
	freopen("wheat.in","r",stdin);
	freopen("wheat.out","w",stdout);
	scanf("%d%d",&n,&m);
	m<<=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",val+i,val_tot+i,y+i);
		swch45(val_tot[i],y[i]);
		tmp[i]=val_tot[i],tmp[i+n]=val_tot[i]+m;
	}
	sort(tmp+1,tmp+1+n+n);
	k=0;
	tmp[0]=-1;
	for(int i=1;i<=n+n;i++)
		if(tmp[i]!=tmp[i-1])tmp[++k]=tmp[i];
	for(int i=1;i<=n;i++){
		left2=lower_bound(tmp+1,tmp+1+k,val_tot[i])-tmp;
		right2=lower_bound(tmp+1,tmp+1+k,val_tot[i]+m)-tmp;
		a[i]=segMMT{left2,right2,y[i],val[i]};
		a[i+n]=segMMT{left2,right2,y[i]+m,-val[i]};
	}
	sort(a+1,a+1+n+n,cmp);
	for(int i=1;i<=n+n;i++){
		t.insert(a[i].left2,a[i].right2,a[i].f,1,n+n,1);
		ans=max(ans,t.bgmx[1]);
	}
	printf("%d",ans);
	return 0;
}
/*
  maybe this will work?
  顺时针（逆时针）转 pi/4 rad。这样小明吃的就是一个平行于坐标轴的正方形里的麦子。
			/---------\
		   /		   \
		  /				\
		 /				 \
		 \				 /
		  \				/
		   \		   /
			\---------/（虚线不存在）
  对于一块麦地，使小明能拿到它的起始点也一定在一个平行于坐标轴的正方形里，
  被正方形覆盖最多的就是机器的点位
  对每块麦地存正方形，扫描线。
 */
