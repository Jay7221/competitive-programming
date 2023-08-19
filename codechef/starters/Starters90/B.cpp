#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> freq(26);
    for(char ch : s){
        ++freq[ch - 'a'];
    }
    int ans;
    if((n % 2) == 0){
        ans = 1;
        for(int i = 0; i < 26; ++i){
            if(freq[i] % 2 == 1){
                ans = 0;
                break;
            }
        }
    }else{
        int odd = 0, even = 0;
        for(int i = 0; i < 26; ++i){
            if(freq[i] > 0){
	            if(freq[i] % 2 == 0){
	                ++even;
	            }else{
	                ++odd;
	            }
            }
        }
        ans = 2;
        if(odd > 1){
            ans = 0;
        }else{
            if(even > 0){
                ans = 1;
            }else{
                ans = 2;
            }
        }
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
