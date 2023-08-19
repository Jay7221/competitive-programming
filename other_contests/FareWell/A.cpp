#include<bits/stdc++.h>
using namespace std;
string solve(){
    vector<char> mp(26);
    for(int i = 0; i < 26; ++i){
        cin >> mp[i];
    }
    map<string, int> freq;
    auto get = [&](string s){
        string ans;
        for(char ch : s){
            ans.push_back(mp[ch - 'A']);
        }
        return ans;
    };
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        ++freq[get(s)];
    }
    for(auto [u, v] : freq){
        if(v > 1){
            return "YES";
        }
    }
    return "NO";
}
int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        cout << "Case #" << t << ": " << solve() << "\n";
    }
    return 0;
}
