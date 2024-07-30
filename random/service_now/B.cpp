#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> freq;
    int ans = 0;
    int l = 0;
    for(int i = 0; i < n; ++i){
        ++freq[s[i]];
        while(freq[s[i]] > 2){
            --freq[s[l]];
            ++l;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << '\n';
}
