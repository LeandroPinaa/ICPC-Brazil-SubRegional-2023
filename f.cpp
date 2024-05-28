#include <bits/stdc++.h>
using namespace std;
#define NMAX 10004
typedef long long int ll;

int cansa[NMAX],descansa[NMAX];

int main(){
    ll N,C,R,qtd=0,i,j; //cansa e rest
    cin >> N >> C >> R;
    for(i=1;i<=C;i++) cin >> cansa[i];
    for(i=1;i<=R;i++) cin >> descansa[i];
    i=1; j=1;
    while(true){
        if(i>C){
            if(j>R) break;
            N += descansa[j++];
            qtd++;
        }
        else{
            if(N>=cansa[i]){
                N -= cansa[i++];
                qtd++;
            }
            else{
                if(j>R) break;
                N += descansa[j++];
                qtd++;
            }
        }
    }
    cout << qtd << endl;
}