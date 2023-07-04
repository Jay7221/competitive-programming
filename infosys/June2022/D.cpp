#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    int ans = 0;
    ll even = 0;
    ll odd = 0;
    ll len = 1;
    for(int i = 0; i < 26; ++i){
        ll f;
        cin >> f;
        even += 2 * (f / 2);
        odd += f % 2;
    }
    while((odd + even) >= len){
        if(len % 2 == 0){
            if(even >= len){
                even -= len;
            }
            else{
                break;
            }
        }
        else{
            if(odd > 0){
                if(even >= len - 1){
                    even -= len - 1;
                    --odd;
                }
                else{
                    break;
                }
            }else{
                if(even >= len + 1){
                    even -= len + 1;
                    ++odd;
                }else{
                    break;
                }
            }
        }
        ++len;
        ++ans;
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
