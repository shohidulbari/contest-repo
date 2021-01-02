#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 7;

ll iterative_calc(ll a, ll b ){
    ll result = 1;
    while(b > 0){
        if(b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b = b / 2;
    }
    return result;
}

ll recursive_calc(ll a, ll b){
    if(b == 0) return 1ll;
    ll result = recursive_calc(a, b / 2);
    if(b & 1) return (result * result * a) % mod;
    else return (result * result) % mod;
}

int main(){
    cout<<iterative_calc(17, 100)<<endl;
    cout<<recursive_calc(17, 100)<<endl;
}