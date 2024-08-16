#include<cstdio>
#include<cstring>
#include<algorithm>
#define inc(x)(x=(x==500)?1:x+1)
using namespace std;
namespace Stocklink{
	const int Blk=500;
	const long long inf=1e18;
	int n,m,val[100010],head,tail;
	struct Node{
		Node *nxt;
		int num[1510],sor[1510],dlt,cov,size;
		bool rev;
		long long sum;
		Node();
		inline void push();
		inline void Sort(){sort(sor+1,sor+size+1);}
		long long getsum();
		long long getMax();
		long long getMin();
	}*null,*Head,P[510],*q[510];
	Node::Node(){
		nxt=null;
		dlt=0,size=0,sum=0,rev=0,cov=0;
		memset(num,0,sizeof(num));
		memset(sor,0,sizeof(sor));
	}
	inline void Node::push(){
		if (rev!=false){
			for (int i=1;i<=size/2;i++)
				swap(num[i],num[size-i+1]);
			rev=false;
		}
		if (dlt!=0){
			for (int i=1;i<=size;i++){
				num[i]+=dlt;sor[i]+=dlt;
			}
			sum+=(long long)dlt*size;dlt=0;
		}
		if (cov!=0){
			for (int i=1;i<=size;i++)
				num[i]=sor[i]=cov;
			sum=(long long)cov*size;cov=0;
		}
	}
	inline long long Node::getsum(){
		long long ans=sum;
		if (dlt!=0) ans+=(long long)dlt*size;
		if (cov!=0) ans=(long long)cov*size;
		return ans;
	}
	inline long long Node::getMax(){
		long long ans=sor[size];
		if (dlt!=0) ans+=dlt;
		if (cov!=0) ans=cov;
		return ans;
	}
	inline long long Node::getMin(){
		long long ans=sor[1];
		if (dlt!=0) ans+=dlt;
		if (cov!=0) ans=cov;
		return ans;
	}
	Node *New(){inc(head);*q[head]=Node();return q[head];}
	inline void Del(Node *k){
		inc(tail);
		q[tail]=k;
	}
	inline void Build(){
		int tail;
		Node *w,*now;
		for (int i=1;i<=n;i=tail+1){
			tail=min(i+Blk-1,n);
			w=New();
			for (int j=i;j<=tail;j++){
				++w->size;
				w->num[w->size]=val[j];
				w->sor[w->size]=val[j];
				w->sum+=val[j];
			}
			w->Sort();
			if (Head==null) Head=w;
			else now->nxt=w;
			now=w;
		}
	}
	inline void find(int cur,Node* &now,int &pos){
		now=Head;
		while (cur-now->size>0&&now!=null){
			cur-=now->size;now=now->nxt;
		}
		pos=cur;now->push();
	}
	inline void Split(Node *now,int pos){
		if (pos==now->size) return;
		Node *w=New();
		now->push();
		memcpy(w->num+1,now->num+pos+1,(now->size-pos)*4);
		w->size=now->size-pos;
		now->size=pos;w->sum=0;
		for (int i=1;i<=w->size;i++){
			w->sum+=w->num[i];
			w->sor[i]=w->num[i];
		}
		now->sum-=w->sum;
		memcpy(now->sor+1,now->num+1,now->size*4);
		now->Sort();w->Sort();
		w->nxt=now->nxt;now->nxt=w;
	}
	inline void Merge(Node *now,Node *suc){
		now->push();suc->push();
		memcpy(now->num+now->size+1,suc->num+1,suc->size*4);
		memcpy(now->sor+now->size+1,suc->sor+1,suc->size*4);
		now->size+=suc->size;
		now->sum+=suc->sum;
		now->Sort();
		now->nxt=suc->nxt;Del(suc);
	}
	inline void Balance(Node *now){
		while (now!=null){
			if (now->size>Blk*2) Split(now,now->size/2);
			else
				if (now->size<Blk/2)
					if (now->nxt==null) break;
			else
				if (now->nxt->size+now->size<=Blk*2) Merge(now,now->nxt);
			else now=now->nxt;
			else now=now->nxt;
		}
	}
	inline void Insert(int cur,int val){
		Node *now;
		int pos;
		find(cur,now,pos);Split(now,pos);
		pos=lower_bound(now->sor+1,now->sor+now->size+1,val)-now->sor;
		for (int i=now->size;i>=pos;i--)
			now->sor[i+1]=now->sor[i];
		now->sor[pos]=val;
		now->size++;now->num[now->size]=val;
		now->sum+=val;Balance(now);
	}
	inline void Delete(int cur){
		Node *now;
		int pos,val;
		find(cur,now,pos);Split(now,pos);
		val=now->num[now->size];
		pos=lower_bound(now->sor+1,now->sor+now->size+1,val)-now->sor;
		for (int i=pos;i<now->size;i++)
			now->sor[i]=now->sor[i+1];
		now->size--;now->sum-=val;
		Balance(now);
	}
	inline void Reverse(int left,int right){
		Node *L,*R,*st[510],*ptr,*suc;
		int posL,posR,top=0;
		find(left-1,L,posL);Split(L,posL);
		find(right,R,posR);Split(R,posR);
		ptr=L;suc=R->nxt;
		do{
			ptr=ptr->nxt;
			st[++top]=ptr;
			ptr->rev^=1;
		}while (ptr!=R);
		st[1]->nxt=suc;
		for (int i=top;i>1;i--)
			st[i]->nxt=st[i-1];
		L->nxt=st[top];
		Balance(L);
	}
	inline void Revolve(int left,int right,int k){
		Node *L,*R,*K,*l,*r;
		int posL,posR,posK;
		find(left-1,L,posL);Split(L,posL);
		find(left+k-1,K,posK);Split(K,posK);
		find(right,R,posR);Split(R,posR);
		l=L->nxt;r=K;
		L->nxt=K->nxt;
		r->nxt=R->nxt;R->nxt=l;
		Balance(L);
	}
	inline void Add(int left,int right,int val){
		Node *L,*R,*ptr;
		int posL,posR;
		find(left-1,L,posL);Split(L,posL);
		find(right,R,posR);Split(R,posR);
		ptr=L;
		do{
			ptr=ptr->nxt;
			if (ptr->cov!=0) ptr->cov+=val;
			else ptr->dlt+=val;
		}while (ptr!=R);
		Balance(L);
	}
	inline void Cover(int left,int right,int val){
		Node *L,*R,*ptr;
		int posL,posR;
		find(left-1,L,posL);Split(L,posL);
		find(right,R,posR);Split(R,posR);
		ptr=L;
		do{
			ptr=ptr->nxt;
			if (ptr->dlt!=0) ptr->dlt=0;
			ptr->cov=val;
		}while (ptr!=R);
		Balance(L);
	}
	inline long long Asksum(int left,int right){
		Node *L,*R,*ptr;
		int posL,posR;
		long long ans=0;
		find(left-1,L,posL);Split(L,posL);
		find(right,R,posR);Split(R,posR);
		ptr=L;
		do{
			ptr=ptr->nxt;
			ans+=ptr->getsum();
		}while (ptr!=R);
		Balance(L);
		return ans;
	}
	inline long long Askdif(int left,int right){
		Node *L,*R,*ptr;
		int posL,posR;
		long long Max,Min;
		find(left-1,L,posL);Split(L,posL);
		find(right,R,posR);Split(R,posR);
		ptr=L;Max=-inf;Min=inf;
		do{
			ptr=ptr->nxt;
			Max=max(Max,ptr->getMax());
			Min=min(Min,ptr->getMin());
			
		}while (ptr!=R);
		Balance(L);
		return Max-Min;
	}
	inline long long Askabs(int left,int right,int val){
		Node *L,*R,*ptr;
		int posL,posR,pos,tmp;
		long long ans=inf;
		find(left-1,L,posL);Split(L,posL);
		find(right,R,posR);Split(R,posR);
		ptr=L;
		do{
			ptr=ptr->nxt;
			if (ptr->cov!=0){
				tmp=ptr->cov-val;
				if (tmp<0) tmp=-tmp;
				ans=min(ans,(long long)tmp);
				continue;
			}
			tmp=val-ptr->dlt;
			pos=lower_bound(ptr->sor+1,ptr->sor+ptr->size+1,tmp)-ptr->sor;
			if (pos<=ptr->size)
				ans=min(ans,(long long)ptr->sor[pos]-tmp);
			if (pos!=1)
				ans=min(ans,(long long)tmp-ptr->sor[pos-1]);
		}while (ptr!=R);
		Balance(L);
		return ans;
	}
	inline int Asksml(int left,int right,int val){
		Node *L,*R,*ptr;
		int posL,posR,pos,tmp;
		int ans=0;
		find(left-1,L,posL);Split(L,posL);
		find(right,R,posR);Split(R,posR);
		ptr=L;
		do{
			ptr=ptr->nxt;
			if (ptr->cov!=0){
				if (ptr->cov<val) ans+=ptr->size;
				continue;
			}
			tmp=val-ptr->dlt;
			pos=lower_bound(ptr->sor+1,ptr->sor+ptr->size+1,tmp)-ptr->sor;
			ans+=pos-1;
		}while (ptr!=R);
		Balance(L);
		return ans;
	}
	inline int divide(int *val,int l,int r,int x){
		int mid,ans=0;
		while (l<=r){
			mid=(l+r)>>1;
			if (val[mid]<=x){
				ans=max(ans,mid);l=mid+1;
			}else r=mid-1;
		}
		return ans;
	}
	inline int check(Node *L,Node *R,int val){
		Node *ptr=L;
		int cnt=0,pos,tmp;
		do{
			ptr=ptr->nxt;
			if (ptr->cov!=0){
				if (ptr->cov<=val) cnt+=ptr->size;
				continue;
			}
			tmp=val-ptr->dlt;
			pos=divide(ptr->sor,1,ptr->size,tmp);
			cnt+=pos;
		}while (ptr!=R);
		return cnt;
	}
	inline long long Askord(int left,int right,int k){
		Node *L,*R/*,ptr*/;
		int posL,posR/*,pos*/;
		long long l,r,mid;
		find(left-1,L,posL);Split(L,posL);
		find(right,R,posR);Split(R,posR);
		l=0;r=2147483647;
		while (l!=r){
			mid=(l+r)>>1;
			if (check(L,R,mid)>=k) r=mid;
			else l=mid+1;
		}
		Balance(L);
		return l;
	}
}
using namespace Stocklink;
int main()
{
	null=new Node;*null=Node();
	head=0;tail=500;Head=null;
	for (int i=0;i<=500;i++){
		P[i]=Node();q[i]=P+i;
	}
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&val[i]);
	Build();scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int opt;scanf("%d",&opt);
		switch (opt){
			case 1:{
				int x,v;
				scanf("%d%d",&x,&v);
				Insert(x,v);break;
			}
			case 2:{
				int x;scanf("%d",&x);
				Delete(x);break;
			}
			case 3:{
				int x,y;scanf("%d%d",&x,&y);
				Reverse(x,y);break;
			}
			case 4:{
				int x,y,k;
				scanf("%d%d%d",&x,&y,&k);
				Revolve(x,y,y-x+1-k);break;
			}
			case 5:{
				int x,y,v;
				scanf("%d%d%d",&x,&y,&v);
				Add(x,y,v);break;
			}
			case 6:{
				int x,y,v;
				scanf("%d%d%d",&x,&y,&v);
				Cover(x,y,v);break;
			}
			case 7:{
				int x,y;scanf("%d%d",&x,&y);
				printf("%lld\n",Asksum(x,y));break;
			}
			case 8:{
				int x,y;scanf("%d%d",&x,&y);
				printf("%lld\n",Askdif(x,y));break;
			}
			case 9:{
				int x,y,v;
				scanf("%d%d%d",&x,&y,&v);
				printf("%lld\n",Askabs(x,y,v));break;
			}
			case 10:{
				int x,y,k;
				scanf("%d%d%d",&x,&y,&k);
				printf("%lld\n",Askord(x,y,k));break;
			}
			case 11:{
				int x,y,v;
				scanf("%d%d%d",&x,&y,&v);
				printf("%d\n",Asksml(x,y,v));break;
			}
		}
	}
	return 0;
}
