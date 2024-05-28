#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007

ll fastexp(ll b, ll e){
    if(e==0) return 1;
    ll ans = fastexp(b,e/2);
    ans = (ans*ans)%MOD;
    if(e%2==0) return ans;
    return (ans*b)%MOD;
}

ll fastmulti(ll a, ll b){
    if(a==0) return 0;
    ll ans = fastmulti(a/2,b);
    ans = (2*ans)%MOD;
    if(a%2==0) return ans;
    return (ans+b)%MOD;
}

int main(){
    ll N,x,resp=0,soma=0;
    map<ll,ll>m;
    m[1] = 1;
    cin >> N;
    while(N--){
        cin >> x;
        soma += x;
        if(soma%2!=0) m[soma]++;
        resp += m[soma]; //1 3 5
    }
    cout << resp << endl;
}
/*
10
1 0 0 1 1 0 1 1 1 0

o que eu preciso:
alguma estrutura de dados ou alguma técnica em st para contar todos os segmentos em ordem de um vetor,
e contar quantos segmentos possuem soma impar
*/