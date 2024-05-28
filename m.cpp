#include <bits/stdc++.h>
using namespace std;
#define NMAX 105
#define INF 999999999
typedef pair<int,int>pii;

int grafo[NMAX][NMAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,x,i,j,k;
    set<pii>s;
    cin >> N;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            cin >> x;
            grafo[i][j] = x;
        }
    }  
    bool flag=true;
    long long int qtd=0;
    for(k=1;k<=N;k++){
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                if(grafo[i][k]+grafo[k][j]<grafo[i][j]){
                    flag=false;
                    break;
                }
                if(grafo[i][j]!=0 && grafo[i][k]!=0 && grafo[k][j]!=0 && grafo[i][k]+grafo[k][j]==grafo[i][j]){
                    if(s.find({i,j}) == s.end()){
                        s.insert({i,j});
                        s.insert({j,i});
                        qtd++;
                    }
                    //cout << "k=" << k << endl;
                    //cout << "i=" << i << endl;
                    //cout << "j=" << j << endl << endl;
                }
            }
            if(!flag) break;
        }
        if(!flag) break;
    }
    if(!flag) cout << -1 << endl; //incoerente
    else{
        cout << qtd << endl;
    }
}