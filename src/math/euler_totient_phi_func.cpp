#include<bits/stdc++.h>

using namespace std;

using ll = long long;

//Complexity is O(sqrt(n))
ll euler_phi(ll n){
    ll res = n;
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if(n > 1) res -= res / n;
    return res;
}



int main(){
    cout<<euler_phi(21)<<endl;
}