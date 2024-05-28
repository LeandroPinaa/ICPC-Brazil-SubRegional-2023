#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,x,altura,qtd=0;
    cin >> N >> altura;
    while(N--){
        cin >> x;
        if(x<=altura) qtd++;
    }
    cout << qtd << endl;
}