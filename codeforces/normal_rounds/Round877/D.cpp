#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> c(q);
    string s;
    cin >> s;
    for(int i = 0; i < q; ++i){
        cin >> c[i];
        --c[i];
    }

    set<int> st;
    for(int i = 0; i < n; i += 2){
        if(s.substr(i, 2) != "()"){
            st.insert(i);
        }
    }
    for(int i: c){
        s[i] ^= 1;
        i -= i & 1;

        if(s.substr(i, 2) != "()"){
            st.insert(i);
        }else{
            st.erase(i);
        }
        bool flag = false;
        if(n % 2 == 0){
            if(st.size() > 0){
                int l = *st.begin();
                int r = *st.rbegin();
                if(s.substr(l, 2) == "((" && s.substr(r, 2) == "))"){
                    flag = true;
                }
            }else{
                flag = true;
            }
        }
        if(flag){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
