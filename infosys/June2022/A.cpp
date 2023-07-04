#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>
void debug(T &a){
    for(int elem : a){
        cerr << elem << ' ';
    }
    cerr << '\n';
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<ll> b = a;
    for(int i = 1; i < n; ++i){
        b[i] = min(b[i], b[i - 1]);
    }
    set<int> st;
    st.insert(0);
    for(int i = 1; i < n; ++i){
        if(b[i] != b[i - 1]){
            st.insert(i);
        }
    }
    for(int j = 0; j < m; ++j){
        int x, y;
        cin >> x >> y;
        --x;
        a[x] -= y;
        b[x] = min(a[x], b[x]);
        if(x > 0){
            int i = *(--st.lower_bound(x));
            if(b[i] > b[x]){
                st.insert(x);
            }
        }
        auto it = st.upper_bound(x);
        vector<int> erase;
        while(it != st.end()){
            int j = *it;
            if(b[j] >= b[x]){
                erase.push_back(j);
            }else{
                break;
            }
            ++it;
        }
        for(int i : erase){
            st.erase(i);
        }
        cout << st.size() << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
