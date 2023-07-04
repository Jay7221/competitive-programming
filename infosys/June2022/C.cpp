#include<bits/stdc++.h>
using namespace std;
#define ll long long
int LIS(vector<int> a){
    vector<int> l;
    for(int elem : a){
        if(elem > l.back()){
            l.push_back(elem);
        }else{
            int i = lower_bound(l.begin(), l.end():q
        }
    }
    return l.size();
}
