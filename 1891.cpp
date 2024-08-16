#include<iostream>
using namespace std;
const int maxn = 200 + 10;
const int table[5][5]={{0,0,1,1,0},
                       {1,0,0,1,0},
                       {0,1,0,0,1},
                       {0,0,1,0,1},
                       {1,1,0,0,0}};

int main() {
    int n,na,nb;
    int A[maxn],B[maxn];

    cin>>n>>na>>nb;
    for(int i=0;i<na;i++) cin>>A[i];
    for(int i=0;i<nb;i++) cin>>B[i];
    int qa=0,qb=0,suma=0,sumb=0;
    int i=0;
    while(i<n) {
        int x=A[qa++],y=B[qb++];
        suma+= table[x][y];
        sumb+= table[y][x];
        if(qa==na) qa=0; if(qb==nb) qb=0;
        i++;
    }
    cout<<suma<<" "<<sumb;
    return 0;
}
