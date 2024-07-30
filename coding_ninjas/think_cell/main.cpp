#include "interval_map.cpp"
#include "test.cpp"
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){
    int q, beg;
    cin >> q >> beg;
    Value begVal = beg;
    interval_map<Key, Value> mp(begVal);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int k1, k2, v;
            cin >> k1 >> k2 >> v;
            Key key1 = k1, key2 = k2;
            Value val = v;
            mp.assign(key1, key2, val);

            int prev = beg;
            for(auto [u, v]: mp.m_map){
                assert(prev != v.value);
                prev = v.value;
            }

            /*
            for(auto [u, v]: mp.m_map){
                cerr << u.value << ' ' << v.value << '\n';
            }
            cerr << "---------------\n";
            */
        }
        else{
            int k;
            cin >> k;
            Key key = k;
            cout << mp[key].value << '\n';
        }
    }
    return 0;
}
