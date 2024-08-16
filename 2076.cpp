#include <bits/stdc++.h>
using namespace std;
struct bigint {
   vector<int> digits;
   bigint(int x) {
      digits.push_back(x);
   }
   void output(){
      int n=digits.size();
      printf("%d",digits[--n]);
      while(n>0)
      	printf("%09d",digits[--n]);
      printf("\n");
   }
   void operator += (const bigint &b) {
      int carry=0;
      for(int i=0;i<digits.size()||i<b.digits.size()||carry;++i){
         int x=carry;
         if(i<digits.size())
         	x+=digits[i];
         if(i<b.digits.size())
         	x+=b.digits[i];
         carry = x >= 1000000000;
         if(carry)x-=1000000000;
         if(i<digits.size())
         	digits[i]=x;
         else
         	digits.push_back(x);
      }
   }
};
char S[10010];
int main() {
	freopen("roam.in", "r", stdin);
	freopen("roam.out", "w", stdout);
   fgets(S,10010,stdin);
   int i=0;
   while(S[i]!='\n') i++;
   S[i]='\0';
   bigint currA(1),currB(0);
   for(int i=strlen(S)-1;i>=0;i--){
      bigint nextA( 0 ), nextB( 0 );
      if(S[i]=='*'||S[i]=='P'){ 
         nextA+=currA;
         nextB+=currB;
      }
      if(S[i]=='*'||S[i]=='L'){ 
         nextA+=currA;
         nextA+=currA;
         nextB+=currB;
      }
      if(S[i]=='*'||S[i]=='R'){ 
         nextA+=currA;
         nextA+=currA;
         nextB+=currA;
         nextB+=currB;
      }
      currA=nextA;
      currB=nextB;
   }
   currA+=currB;
   currA.output();
   return 0;
}
