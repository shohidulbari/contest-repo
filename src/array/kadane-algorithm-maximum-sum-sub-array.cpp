#include<bits/stdc++.h>

using namespace std;


int kadane(vector<int>& vals){
    int global_max = INT_MIN;
    int local_max = 0;
    for(int i=0; i< vals.size(); i++){
        local_max = local_max + vals[i];
        global_max = max(global_max, local_max);
    }
    return global_max;
}