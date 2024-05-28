#include <bits/stdc++.h>
using namespace std;
#define NMAX 1000005
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int freq[NMAX];
int proximo[NMAX]; //se x=18, o proximo[18] = 9, e assim por diante

int soma(int x){
    //22
    string s = to_string(x);
    int soma=0;
    for(int i=0;i<s.size();i++){
        int j = s[i]-'0';
        soma += j;
    }
    return soma;
}

int32_t main(){ faster
    int N,K,x;
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> x;
        freq[x]++; //counting sort
    }
    for(int i=0;i<NMAX;i++){
        proximo[i] = i - soma(i);
    }
    int resp = 0;
    for(int i=NMAX-1;i>=0;i--){ //começa pelo maior nmr
        K -= freq[i];
        freq[proximo[i]] += freq[i]; //se era 22, 22 vira 18, dai se tinha 3 nmrs 22, os 3 vira 18, entao aumenta a freq de 18
        if(K<=0){
            resp = i;
            break;
        }
    }
    cout << soma(resp) << endl;
}
/*
5 3
22 15 7 2 1
resp: 6
*/