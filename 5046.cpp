#include<bits/stdc++.h>
using namespace std;
int k,a[1001],mm,res,s_n;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	cin>>k;
	res=0;
	s_n=0X7fffffff;
	for(int i=0;i<k;i++)
	    cin>>a[i];
	sort(a,a+k,cmp);
	mm=a[0];
	int n=k,num;
	while(n>0){
	    num=1; 
	    int b[1001]={0};
	    for(int i=0;i<n;i++)
	        b[i]=a[i];
	    for(int i=n;i<k;i++){
	        int ma=0X7fffffff,p;
	        for(int j=0;j<n;j++)
	            if(b[j]<ma)
	                p=j,ma=b[j];
	        b[p]+=a[i];
		}
	    for(int i=0;i<n;i++)
	        num=num+abs(mm-b[i]);
	    if(num<s_n)
	        s_n=num,res=n;
	    n--;
	}
	cout<<res;
	return 0;
}
