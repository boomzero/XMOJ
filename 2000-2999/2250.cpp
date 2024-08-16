#include <bits/stdc++.h>
using namespace std;
const int m=1000000; 
int top,k,n;
long long sta[m];
long long a;
char str[10];
bool is_empty1(){
	if(top==0){
		return true;
	}
	else{
		return false;
	}
}
int top1(){
	return sta[top-1];
}
void push1(){
	sta[top++]= a;
}
int pop1(){
	top--;
	return sta[top];
}
int main(){
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%s",str);
		if(str[0]=='T'){
			//top
			if(is_empty1()==true){
				printf("-1");
				break;
			}
			printf("%lld\n",top1());
		}
		else if(str[0]=='P'&&str[1]=='u'){
			//push
			scanf("%d",&n);
			for(int j=0;j<n;j++){
				scanf("%lld",&a);
				push1();
			}
		}
		else if(str[0]=='P'&&str[1]=='o'){
			//pop
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				if(is_empty1()==true){
					printf("-1");
					break;
				}
				printf("%lld ",pop1());
			}
			printf("\n");
		}
		else{
			//size
			printf("%lld\n",top);
		}
	}
}
