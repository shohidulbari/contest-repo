#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


//Trial Division...Improved... All Prime Number Above 3 are in either 6k + 1 or 6k + 5 form
bool isPrime(ll n) {
    if (n < 2ll) return false;
    if (n < 4ll) return true;
    if (!(n & 1ll))   return false;
    if (n % 3ll == 0) return false;

    int limit = sqrt(n);
    for (int i = 5; i <= limit; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
             return false;

    return true;
}

ll binpower(ll base, ll e, ll n){
    ll result = 1;
    base = base % n;
    while(e){
        if(e&1) result = (result * base) % n;
        base = (base * base) % n;
        e = e>>1;
    }
    return result;
}

/*
*Using Fermet's Theorem
*Fermet't Theorem states that a^(n - 1) === 1 mod n if n is prime
*vulnerable to Carmichael numbers
*Carmichael Number: Some composite number which satisfy fermet's test for all a coprime to n
*/

bool isPrimeFermet(ll n, ll iter = 5){
    if(n < 4ll) return n == 2ll or n == 3ll;
    for(int i=0; i<iter; i++){
        ll a = 2 + rand() % (n - 3);
        if(binpower(a, n - 1, n) != 1) return false;
    }
    return true;
}

/*
*Using Millar-Rabin Primality Test
*For an odd number n, n-1 is even and we can factor out all power of 2. 
*We can write- n - 1 = 2 ^(s).d with d odd
*For a base 2<=a<=n-2 we check either
*a^d = 1 mod n
*or
*a^(2^r.d) = -1 mod n holds for 0<=r<=s-1
*/

bool isComposite(ll n, ll a, ll d, ll s){
    ll x = binpower(a, d, n);
    if(x == 1ll or x == n - 1)
        return false;
    for(int r = 1; r<s; r++){
        x = x * x % n;
        if(x == n - 1)
            return false;
    }
    return true;
}

//Return's True if n is probably prime
bool isPrimeMillerRabin(ll n, ll iter = 5){
    if(n < 4ll)
        return n == 2ll or n == 3ll;
    ll s = 0;
    ll d = n - 1ll;
    while(d & 1ll == 0){
        d = d >> 1;
        s++;
    }

    for(int i=0; i<iter; i++){
        ll a = 2 + rand() % (n - 3);
        if(isComposite(n, a, d, s))
            return false;
    }
    return true;
}


int main(){
    if(isPrimeFermet(37ll)) cout<<"Test OK"<<endl;
    return 0;
}