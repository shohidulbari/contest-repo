#include<bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j > 0 and s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string text = "adfhsdkfksdhfjksdfhjskfjsjhfksdhfkjsdfjks";
    string query = "jksd";
    vector<int> prefix = prefix_function(query + "#" + text);
    int n = query.size();
    int pos = -1;
    for(int i=0; i<prefix.size(); i++){
        if(prefix[i] == n){
            pos = i - 2*n;
            break;
        }
    }
    if(pos == -1) cout<<"Not Found"<<endl;
    else cout<<"Found at pos..."<<pos<<endl;

    return 0;
}