#include <bits/stdc++.h>
using namespace std;
int n,a[1010],b[1010],ans;
bool ok;
void doit(){
	for(int i=0;i<n;i++){
		b[i]=a[i]/2+a[(i-1+n)%n]/2;
	}
	for(int i=0;i<n;i++){
		a[i]=b[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]%2==1){
			a[i]-=1;
		}
	}
	ok=true;
	for(int i=1;i<n;i++){
		if(a[i]!=a[0]){
			ok=false;
			break;
		}
	}
}

int main()
{
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		ok=false;
		ans=0;
		while(!ok){
			doit();
			++ans;
		}
		cout<<ans<<" "<<a[0]*n<<endl;
	}
    return 0;
}
