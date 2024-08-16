#include<bits/stdc++.h>
using namespace std;
int g,l[400],c[400][400],lz[400],ly[400];
char s[400];
int f=0,fl=0;
int w=0,W=0,H=0,Fl=0,Fla=1,MW,MH;
int cha(){
    for(int i=1;i<g;i++){
        int f=1;
        if(l[i]==l[g]){
            for(int j=0;j<l[i];j++){
                if(c[i][j]!=c[g][j]){
                    f=0;
                    break;
                }
            }
        }
        if(f){
            return 1;
        }
    }
    return 0;
}
void fi(){
    cin>>s;
    if(s[0]=='F'){
        f++;
        g++;
        if(Fl==1){
            Fla=f;
        }
        cin>>s;
        l[g]=strlen(s);
        for(int i=0;i<l[g];i++){
            c[g][i]=s[i];
            if(cha()){
                fl=1;
            }
        }
        cin>>s;
        if(s[0]=='n'){
            lz[f]=0;
        }
        else{
            lz[f]=0;
            int r=0;
            while(s[r]!='\0'){
                lz[f]=lz[f]*10+(s[r]-'0');
                r++;
            }
        }    
        cin>>s;
        if(s[0]=='n'){
            ly[f]=0;
        }
        else{
            ly[f]=0;
            int r=0;
            while(s[r]!='\0'){
                ly[f]=ly[f]*10+(s[r]-'0');
                r++;
            }
        }
        Fl=0;
    }
    else{
        if(f==Fla){
            if(lz[f]==0){
                if(ly[f]!=0){
                    H=1;
                }
                else{
                    W=w;
                }
            }
            else{
                if(ly[f]==0){
                    w++;
                    W=max(w,W);
                }
                else if(lz[f]<=ly[f]){
                    W=w;
                    H=1;
                }
                else{
                    H=1;
                }
            }
            w=0;
        }
        else if(f<1){
            fl=0;
        }
        else{
            if(lz[f]==0){
                if(ly[f]!=0){
                    w=0;
                }
                H=1;
            }
            else{
                if(ly[f]==0){
                    w++;
                }
                else if(lz[f]>ly[f]){
                    w=0;
                    H=1;
                }
                else{
                    H=1;
                }
            }
        }
        f--;
        g--;
        Fl=1;
    }
} 
int main(){
    int t;
    cin>>t;
    while(t--){
        f=0,fl=0;
        w=0,W=0,H=0;
        MW=0,MH=0;
        g=0;
        int n;
        cin>>n;
        cin>>s;
        int L=strlen(s);
        char S[400];
        for(int i=0;i<L;i++){
            S[i]=s[i];
        }
        for(int i=1;i<=n;i++){
            fi();
            MW=max(MW,W),MH=max(MH,H);
        }
        if(f!=0){
            fl=1; 
        }
        if(fl==1){
            cout<<"ERR"<<endl;
        }
        else{
            int hh=0,ww=0;
            if(S[2]=='n'){
                int r=4;
                while(S[r]<='9'&&'0'<=S[r]){
                    ww=ww*10+(S[r]-'0');
                    r++;
                }
            }
            else{
                hh=1;
            }
            if(MW){
                if(ww==MW){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
            else{
                if(!ww){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
        }
    }
    return 0;
}
