#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int t, q;
    cin >> t >> q;
    priority_queue<pair<int, int>> pq;
    set<int> st;

    auto update = [&](int i){
        st.erase(i);
        if(s1[i] != s2[i]){
            st.insert(i);
        }
    };
    auto block = [&](int i){
        st.erase(i);
    };
    for(int i = 0; i < n; ++i){
        update(i);
    }
    auto debug = [&](){
        for(int elem : st){
            cerr << elem << ' ';
        }
        cerr << '\n';
    };
    for(int time = q; time > 0; --time){
        while(pq.size()){
            int prev, i;
            tie(prev, i) = pq.top();
            if(prev - time < t){
                break;
            }
            pq.pop();
            update(i);
        }


        int type;
        cin >> type;
        if(type == 1){
            int i;
            cin >> i;
            --i;
            pq.push({time, i});
            block(i);
        }else if(type == 2){
            int p1, p2, i1, i2;
            cin >> p1 >> i1 >> p2 >> i2;
            --i1, --i2;
            if(p1 == 1){
                if(p2 == 1){
                    swap(s1[i1], s1[i2]);
                }else{
                    swap(s1[i1], s2[i2]);
                }
            }else{
                if(p2 == 1){
                    swap(s2[i1], s1[i2]);
                }else{
                    swap(s2[i1], s2[i2]);
                }
            }
            update(i1);
            update(i2);
        }else{
            if(st.size() > 0){
                cout << "NO\n";
            }else{
                cout << "YES\n";
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
