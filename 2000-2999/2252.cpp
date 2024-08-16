#include <bits/stdc++.h>
using namespace std;
long long front=0,rear=0,k,n,m=10010;
long long a;
long long q[10010];
char str[10];
bool is_empty1() {
	return front==rear;
}
bool is_full1(){
	return (rear+1)%m==front;
}
long long size1(){
	return (rear-front+m)%m;
}
void enque1(long long x){
	q[rear++]=x;
	rear%=m;
}
long long deque1(){
	if(is_empty1()==true) return -1;
	long long ans=q[front++];
	front%=m;
	return ans;
}
long long front1(){
	if(is_empty1()==true) return -1;
	return q[front];
}
int main(){
	ios::sync_with_stdio(false);
	scanf("%lld",&k);
	for(long long i=0;i<k;i++){
		scanf("%s",str);
		if(str[0]=='P'&&str[1]=='u'){
			scanf("%lld",&n);
			for(long long j=0;j<n;j++){
				scanf("%lld",&a);
				enque1(a);
			}
		}
		else if(str[0]=='S'){
			printf("%lld",size1());
			printf("\n");
		}
		else if(str[0]=='F'){
			printf("%lld",front1());
			printf("\n");
		}
		else if(str[0]=='P'&&str[1]=='o'){
			scanf("%lld",&n);
			for(long long i=0;i<n;i++){
				printf("%lld ",deque1());
			}
			printf("\n");
		}
		if(rear==m) rear=0; 
	}
}
