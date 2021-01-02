#include<bits/stdc++.h>

using namespace std;

int extended_gcd(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (y1 * (a / b));
    return d;
}

int main(){
    int tests;
    cin>>tests;
    while(tests--){
        int a , b;
        cin>>a>>b;
        int x, y;
        int d = extended_gcd(a, b, x, y);
        cout<<d<<"="<<a<<"("<<x<<")"<<"+"<<b<<"("<<y<<")"<<endl;
    }
    return 0;
}