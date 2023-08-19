#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>
void debug(T &arr){
    for(char ch : arr){
        cerr << ch << ' ';
    }
    cerr << '\n';
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;

    set<char> st;
    int ind = 0;
    auto fill = [&](int ind){
        for(char ch = l[ind]; ch <= r[ind]; ++ch){
            st.insert(ch);
        }
    };
    fill(0);
    for(int i = 0; i < n; ++i){
        if(st.find(s[i]) != st.end()){
            st.erase(s[i]);
        }
        if(st.size() == 0){
            ++ind;
            if(ind == m){
                break;
            }
            fill(ind);
        }
    }

    bool flag = ((st.size() > 0) || (ind < m));

    if(flag){
        cout << "YES\n";
    }else{
        cout << "NO\n";
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
