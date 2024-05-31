#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 1000005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e9
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

pii v[NMAX];

int32_t main(){ faster
    int n,x,varreduras=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x;
        v[i] = {x,i};
    }
    sort(v+1,v+1+n);
    int p = v[1].second;
    for(int i=2;i<=n;i++){
        if(v[i].second < p){ //eh pq esta atras
            varreduras++;
        }
        p = v[i].second;
    }
    int ans = 0;
    while(varreduras){
        ans++;
        varreduras>>=1;
    }
    cout << ans << '\n';
}