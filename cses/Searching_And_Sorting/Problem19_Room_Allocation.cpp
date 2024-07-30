#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main(){
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v;
    vector<int> roomNumber(n);
    for(int i = 0; i < n; ++i){
        int l, r;
        cin >> l >> r;
        v.push_back({l, r, i});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    sort(v.begin(), v.end());
    vector<int> avaliable;
    for(auto [l, r, ind]: v){
        while(!pq.empty() && (pq.top().first < l)){
            avaliable.push_back(roomNumber[pq.top().second]);
            pq.pop();
        }
        pq.push({r, ind});
        if(avaliable.empty()){
            roomNumber[ind] = pq.size();
        }
        else{
            roomNumber[ind] = avaliable.back();
            avaliable.pop_back();
        }
    }
    cout << *max_element(roomNumber.begin(), roomNumber.end()) << '\n';
    for(int i = 0; i < n; ++i){
        cout << roomNumber[i] << ' ';
    }
    cout << '\n';
    return 0;
}
