#include <bits/stdc++.h>
using namespace std;
int a[10110],b[10110],blen,alen,q[10110],qlen,r[10110],rlen;
char s[10010];
void read(int x[],int &xlen)
{
    cin>>s;
    xlen=strlen(s);
    for (int i=0;i<xlen;++i)
		x[xlen-i]=s[i]-'0';
}
bool big(){
	if(rlen!=blen){
		return rlen>blen;
	}
	for(int i=rlen;i>=1;i--){
		if(r[i]!=b[i]){
			return r[i]>b[i];
		}
	}
	return true;//r=b
}
void Minus(){
	for(int i=1;i<=rlen;i++){
		r[i]-=b[i];
	}
	for(int i=1;i<=rlen;i++){
		if(r[i]<0){
			r[i+1]--;
			r[i]=10+r[i];
		}
	}
	while(rlen>1&&r[rlen]==0)
		--rlen;
}
void print(int len,int a[]){
	for(int i=len;i>=1;i--){
		cout<<a[i];
	}
	cout<<endl;
}
int main()
{
    read(a,alen);
    read(b,blen);
    rlen=1;
    for(int i=alen;i>=1;i--){
    	for(int j=rlen;j>=1;j--){
    		r[j+1]=r[j];
    	}
    	r[1]=a[i];
    	if(r[rlen+1]>0)
    		rlen++;
    	while(big()){
    		Minus();
			q[i]++;
    	}
    }
    qlen=alen;
    while(qlen>1&&q[qlen]==0){
    	qlen--;
    }
    print(qlen,q);
    print(rlen,r);
    return 0;
}
