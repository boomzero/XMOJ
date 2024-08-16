#include<bits/stdc++.h>
using namespace std;
#define MAXN 10005
struct ppp{
	int a, b;
}p[MAXN];
int n;
bool cmp( ppp x, ppp y ){
	return x.a * x.b < y.a * y.b;
}
int s[4005], len;
int ans[4005], ans_l(0);
void Mul( int x ){
	int t(len);
	for ( int i = 1; i <= len; ++i ) s[i] *= x;
	for ( int i = 1; i <= len + 5; ++i ){
		if ( s[i] ) t = i;
		s[i + 1] += s[i] / 10;
		s[i] %= 10;
	}
	len = t;
}
void Copy( int c[], int c_l ){
	for ( int i = 1; i <= c_l; ++i ) ans[i] = c[i];
	ans_l = c_l;
}
void Out( int s[], int l ){
	for ( int i = l; i >= 1; --i ) printf( "%d", s[i] );
	putchar('\n');
}
void Div( int x ){
	int c[4005], l(-1);
	for ( int i = 1; i <= len; ++i ) c[i] = s[i];
	for ( int i = len; i >= 1; --i ){
		c[i - 1] += ( c[i] % x ) * 10;
		c[i] /= x;
		if ( c[i] && l == -1 ) l = i;
	}
	if ( ans_l == l ){
		bool flg(0);
		for ( int i = l; i >= 1; --i )
			if ( ans[i] < c[i] ){ flg = 1; break; }
		else break;
		if ( flg ) Copy( c, l );
	}
	if ( ans_l < l ) Copy( c, l );
}
int main(){
	scanf( "%d", &n );
	scanf( "%d%d", &p[0].a, &p[0].b );
	for ( int i = 1; i <= n; ++i ) scanf( "%d%d", &p[i].a, &p[i].b );
	sort( p + 1, p + n + 1, cmp );
	s[1] = 1; len = 1;
	Mul( p[0].a );
	for ( int i = 1; i <= n; ++i )
		Div( p[i].b ), Mul( p[i].a );
	Out( ans, ans_l );
	return 0;
}
