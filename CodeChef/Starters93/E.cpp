#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> blocks;;
    blocks.push_back(1);
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i - 1]){
            ++blocks.back();
        }else{
            blocks.push_back(1);
        }
    }
    vector<int> coins = blocks;
    sort(coins.begin(), coins.end());
    vector<bool> dp(n + 1);
    dp[0] = true;
    for(int c : coins){
        for(int i = n; i >= c; --i){
            dp[i] = (dp[i] | dp[i - c]);
        }
    }
    if((n % 2 == 0) && dp[n / 2]){
        cout << "YES\n";
        string s;
        int sum = 0;
        vector<int> freq(n + 1);
        reverse(coins.begin(), coins.end());
        for(int c : coins){
            if(sum + c <= n / 2){
                sum += c;
                ++freq[c];
            }
        }
        for(int b : blocks){
            if(freq[b] > 0){
                --freq[b];
                while(b--){
                    s.push_back('(');
                }
            }else{
                while(b--){
                    s.push_back(')');
                }
            }
        }
        cout << s << '\n';
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
