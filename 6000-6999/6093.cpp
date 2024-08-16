#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<cstdio>
#include<cstring>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;
const int maxn = 1005;
char ch[maxn][maxn],tmp[maxn];
int n,m,a,b,q;
int p = 131;
ll hashv[maxn][maxn],power[maxn * maxn];
set <ll> Hash;
void calHash() 
{
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			hashv[i][j] = hashv[i][j - 1] * p + ch[i][j] - '0';
		}
	}
	power[0] = 1;
	for(int  i = 1 ; i <= n * m ; i++){
		power[i] = power[i - 1] * p;
	}
}
ll get_hash(ll f[] , int l,int r) 
{
	return f[r] - f[l - 1] * power[r - l + 1];
}
 
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i = 1 ; i <= n ; i++) scanf("%s", ch[i] + 1);
	calHash();
	for(int i = b ; i <= m ; i++){  
		ll s = 0;
		int l = i - b + 1,r = i;
		for(int j = 1 ; j <= n ; j++){
			s = s * power[b] + get_hash(hashv[j],l,r); 
			if(j > a) s -= get_hash(hashv[j - a],l,r) * power[a * b]; 
			if(j >= a) Hash.insert(s); 
		}
	}
	scanf("%d",&q);
	while(q--){
		ll s = 0;
		for(int i = 1 ; i <= a ; i++){
			scanf("%s",tmp + 1);
			for(int j = 1 ; j <= b ; j++){
				s = s * p + tmp[j] - '0';
			}
		}
		if(Hash.count(s)) puts("1");
		else puts("0");
	}
    return 0;
}
