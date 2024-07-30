#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    long long n, m;
    cin >> n >> m;
    vector<long long> quantity_avaliable(m), quantity_needed(m), cost_of_one_unit(m), selling_price(m);
    for(long long i = 0; i < m; ++i){
        cin >> quantity_avaliable[i];
    }
    for(long long i = 0; i < m; ++i){
        cin >> quantity_needed[i];
    }
    for(long long i = 0; i < m; ++i){
        cin >>cost_of_one_unit[i];
    }
    for(long long i = 0; i < m; ++i){
        cin >>selling_price[i];
    }
    vector<long long> dp(n + 1);

    for(long long j = 0; j < m; ++j){
        long long cp = quantity_needed[j] * cost_of_one_unit[j];
        long long sp = selling_price[j];
        long long qa = quantity_avaliable[j];
        long long qn = quantity_needed[j];

        for(long long coin = n; coin >= 1; --coin){
            long long units = min(qa / qn, coin / cp);
            for(long long u = 1; u <= units; ++u){
                dp[coin] = max(dp[coin], dp[coin - u * cp] + sp * u);
            }
        }
        for(long long coin = 1; coin <= n; ++coin){
            dp[coin] = max(dp[coin], dp[coin - 1]);
        }
    }



    cout << dp[n];
    return 0;
}
