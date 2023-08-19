#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const long long inf = numeric_limits<long long>::max() / 2;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n), dp(n, -inf);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<long long>());
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            long long mp = -inf;
            for (int j = i - 1; j >= 0; j--) {
                mp = max(mp, dp[j]);
                dp[i] = max(dp[i], mp + a[j] % a[i] - a[j]);
            }
        }
        cout << accumulate(a.begin(), a.end(), 0LL) + dp[n - 1] << '\n';
    }
}