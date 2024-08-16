#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+7;
typedef long long ll;
#define Ms(a,k) (memset(a,k,sizeof(a)))
int T;
char S[MAXN];
int n,N[MAXN];
int t[MAXN],Pre[MAXN],Suf[MAXN],Per[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	for(cin>>T;T;T--){
		cin>>S+1;n=strlen(S+1);
		N[1]=0;Ms(Pre,0);Ms(Suf,0);Ms(Per,0);
		for(int i=2;i<=n;i++){
			int p=N[i-1];
			while(p!=0&&S[p+1]!=S[i])
				p=N[p];
			if(S[p+1]==S[i])
				p++;
			N[i]=p;
		}
		Ms(t,0);
		for(int i=1;i<=n;i++)
			if((++t[S[i]-'a'+1])&1)Pre[i]=Pre[i-1]+1;
		else Pre[i]=Pre[i-1]-1;
		Ms(t,0);
		for(int i=n;i>=1;i--)
			if((++t[S[i]]-'a'+1)&1)Suf[i]=Suf[i+1]+1;
		else Suf[i]=Suf[i+1]-1;
		ll ans=0;
		for(int i=1;i<n;i++){
			if(i>=2){
				ans+=(ll)Per[Suf[i+1]];
				for(int j=i+i;j<n;j+=i){
					int q=j-N[j];
					if(i%q==0&&j/q>1)
						ans+=(ll)Per[Suf[j+1]];
				}
			}
			for(int j=Pre[i];j<=30;j++)
				Per[j]++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
