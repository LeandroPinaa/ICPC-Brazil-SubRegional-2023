#include <bits/stdc++.h>
using namespace std;
#define NMAX 100005
#define INF 999999999
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N;
int dp[NMAX];
int v[NMAX];
int resp[NMAX];
vector<int>grafo[NMAX];

void DFS(int u, int pai, int novo[]){
   //cout << "u = " << u << endl;
   //for(int i=0;i<=N;i++) cout << novo[i] << " ";
   //cout << endl;
   int p,k;
    for(auto viz:grafo[u]){
        if(viz!=pai){
            p = lower_bound(novo,novo+N+1,v[viz])-novo;
            //cout << "p = " << p << endl;
            int save = novo[p];
            novo[p] = v[viz];        
            k = lower_bound(novo,novo+N+1,INF)-novo;
            //cout << "k = " << k << endl << endl;
            resp[viz] = k-1;
            DFS(viz,u,novo);
            novo[p] = save;
        }
    }
    
}

int32_t main(){
    faster
    int i,x;
    cin >> N;
    dp[0] = -INF;
    for(i=1;i<=N;i++) dp[i] = INF;
    for(i=2;i<=N;i++){
        cin >> x;
        grafo[x].push_back(i);
        grafo[i].push_back(x);
    }
    for(i=1;i<=N;i++) cin >> v[i];
    int p = lower_bound(dp,dp+N+1,v[1])-dp;
    //dp = [-INF,5,INF]
    resp[1] = p;
    dp[p] = v[1];
    DFS(1,-1,dp);
    for(i=2;i<=N;i++) cout << resp[i] << " ";
}