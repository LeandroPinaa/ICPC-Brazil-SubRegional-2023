#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 1000030
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e9
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

int32_t main(){ faster
    map<int,int>m,m2;
    int n,x,soma=0,soma2=0;
    cin >> n;
    int ans = 0, ans2 = 0;
    int k=1,k2=2;
    m[0] = m2[0] = 1;
    while(n--){
        cin >> x;
        soma = ((soma+x)%k+k)%k;
        ans += m[soma];
        m[soma]++;
        soma2 = ((soma2+x)%k2+k2)%k2;
        ans2 += m2[soma2];
        m2[soma2]++;
    }
    cout << ans - ans2 << '\n';
}
/*
3
0 1 0

10
1 0 0 1 1 0 1 1 1 0

*/