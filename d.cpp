#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 302
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define t tuple<int,int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

int dist1[NMAX][NMAX];
int dist2[NMAX][NMAX];
vector<pii>keep;
vector<pii>grafo[NMAX];
vector<int>d(NMAX);
int n,m;

int Dijkstra(int s, int e){
    fill(d.begin(),d.end(),INF);
    d[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>>fila;
    fila.push({0,s});
    while(!fila.empty()){
        auto [dd,u] = fila.top(); fila.pop();
        if(u==e) return d[e];
        if(dd > d[u]) continue;
        for(auto viz:grafo[u]){
            int w = viz.first;
            if((u == s && viz.second == e) || (u==e && viz.second==s)) continue;
            if(d[viz.second] > d[u] + w){
                d[viz.second] = d[u] + w;
                fila.push({d[viz.second],viz.second});
            }
        }
    }
    return d[e];
}

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist2[i][j] = min(dist2[i][j],dist2[i][k]+dist2[k][j]);
            }
        }
    }
}

int32_t main(){ faster
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                dist1[i][j] = dist2[i][j] = INF;
            } 
        }
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        dist1[a][b] = dist1[b][a] = w;
        dist2[a][b] = dist2[b][a] = w;
        grafo[a].push_back({w,b});
        grafo[b].push_back({w,a});
        keep.push_back({a,b});
    }
    floyd();
    for(auto [a,b]:keep){
        int ans = INF;
        if(dist2[a][b]<dist1[a][b]){
            //ja eh garantido q o caminho min não percorre aresta ab
            ans = dist2[a][b];
        }
        else{
            ans = Dijkstra(a,b);
        }
        cout << (ans != INF ? ans : -1) << '\n';
    }
}
/*
4 5
1 2 4
1 3 8
2 3 4
4 1 2
3 4 3


*/