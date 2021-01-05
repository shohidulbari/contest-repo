#include<bits/stdc++.h>

using namespace std;

int search(vector<int>& a, int val){
    int l = -1;
    int r = (int) a.size();

    while(r - l > 1){
        int m = (r + l) / 2;
        if(a[m] == val) return m;
        else if(a[m] < val) l = m;
        else r = m;
    }
    return l;
}

int main(){
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int id = search(v, 4);
    assert (id == 3);
    id = search(v, 10);
    assert (id == 9);
    id = search(v, 7);
    assert (id == 6);
    id = search(v, 1);
    assert (id == 0);
}