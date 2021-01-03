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

using u64 = long long;
using u128 = __uint128_t;

u64 calcpower(u64 a, u64 b, u64 n) {
    a = a % n;
    u64 res = 1;
    while (b) {
        if (b & 1)
            res = (u128)res * a % n;
        a = (u128)a * a % n;
        b >>= 1;
    }
    return res;
}

bool isComposite(u64 n, u64 a, u64 d, int s) {
    u64 x = calcpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

//Return's True if n is probably prime
bool isPrimeMillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (isComposite(n, a, d, s))
            return false;
    }
    return true;
}


int main(){
    if(isPrimeFermet(37ll)) cout<<"Test OK"<<endl;
    return 0;
}