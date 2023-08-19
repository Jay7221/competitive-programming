#include <bits/stdc++.h>
using namespace std;

#define debug_2(a, n, m) for(int i = 0; i < n; i++){for(int j = 0; j < m;j++){cerr << a[i][j] << '\t';} cerr << '\n';}cerr << '\n';
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int t;
    cin >> t;
    while (t-- > 0) {
        int n, m;
        int K;
        cin >> n >> m >> K;

        vector<string> M(n);
        for (int i = 0; i < n; ++i) {
            cin >> M[i];
        }

        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        int px = 0, py = 0;
        dp[0][0] = K;
        for (int s = 0; s < n - 1 + m - 1; ++s) {
            int l = max(0, s - (m - 1));
            int r = min(n - 1, s);

            for (int x = l; x <= r; ++x) {
                int y = s - x;

                int v = M[x][y] - '0';
                auto cnt = dp[x][y];
                // cout << x << "," << y << "::::" << cnt << endl;
                if (x == n - 1 || y == m - 1) {
                    cnt = min(cnt, 1LL);
                }
                if (y + 1 < m) {
                    if (v == 0) {
                        dp[x][y + 1] += (cnt + 1) / 2;
                    } else {
                        dp[x][y + 1] += cnt / 2;
                    }
                }
                if (x + 1 < n) {
                    if (v == 1) {
                        dp[x + 1][y] += (cnt + 1) / 2;
                    } else {
                        dp[x + 1][y] += cnt / 2;
                    }
                }
            }
            int val = M[px][py] - '0';
            assert(dp[px][py] > 0);
            if (py == m - 1) {
                if (dp[px][py] > 1) {
                    val = 0;
                }
            } else if (px == n - 1) {
                if (dp[px][py] > 1) {
                    val = 1;
                }
            } else {
                val ^= (dp[px][py] - 1) & 1;
            }
            // cout << px << "," << py << ": " << val << " " << dp[px][py] << endl;
            if (val == 0) {
                if (py == m - 1) {
                    break;
                }
                ++py;
            } else {
                if (px == n - 1) {
                    break;
                }
                ++px;
            }
        }
        debug_2(dp, n, m)

        cout << px + 1 << ' ' << py + 1 << '\n';
    }
    

    return 0;
}