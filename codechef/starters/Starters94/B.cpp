#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    string s;
    cin >> s;
    auto is_vowel = [&](char c){
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(char ch : vowels){
            if(c == ch){
                return true;
            }
        }
        return false;
    };

    for(int i = 0; i < n; ++i){
        if(is_vowel(s[i])){
            v.push_back(i);
        }
    }

    auto mult = [&](ll a, ll b){
        return ((a * b) % MOD);
    };

    ll ans = 1;
    for(int i = k; i < v.size(); i += k){
        ans = mult(ans, v[i] - v[i - 1]);
    }
    cout << ans << '\n';

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
