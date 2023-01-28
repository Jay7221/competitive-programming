#include<iostream>
using namespace std;
#define ll long long
class Solution {
public:
    int countPalindromes(string s) {
        ll MOD = 1e9 + 7;
        auto add = [&](int a, int b){
            ll x = a, y =  b;
            return (x + y) % MOD;
        };
        auto mult = [&](int a, int b){
            ll x = a, y = b;
            return (x * y) % MOD;
        };
        int n = s.size();
        int dp[n + 1][10][10][6];
        for(int i = 0; i < n + 1; ++i){
            for(int first = 0; first < 10; ++first){
                for(int second = 0; second < 10; ++second){
                    for(int len = 0; len < 6; ++len){
                        dp[i][first][second][len] = 0;
                    }
                }
            }
        }
        for(int first = 0; first < 10; ++first){
            for(int second = 0; second < 10; ++second){
                dp[0][first][second][0] = 1;
            }
        }
        for(int i = 1; i < n + 1; ++i){
            for(int first = 0; first < 10; ++first){
                for(int second = 0; second < 10; ++second){
                    for(int len = 0; len < 6; ++len){
                        dp[i][first][second][len] = dp[i - 1][first][second][len];
                    }
                }
            }
            int cur = s[i - 1] - '0';
            for(int first = 0; first < 10; ++first){
                dp[i][first][cur][2] = add(dp[i][first][cur][2], dp[i - 1][first][cur][1]);
                dp[i][first][cur][4] = add(dp[i][first][cur][4], dp[i - 1][first][cur][3]);
            }
            for(int second = 0; second < 10; ++second){
                dp[i][cur][second][1] = add(dp[i][cur][second][1], dp[i - 1][cur][second][0]);
                dp[i][cur][second][5] = add(dp[i][cur][second][5], dp[i - 1][cur][second][4]);
            }
            for(int first = 0; first < 10; ++first){
                for(int second = 0; second < 10; ++second){
                    dp[i][first][second][3] = add(dp[i][first][second][3], dp[i - 1][first][second][2]);
                }
            }
        }
        int ans = 0;
        for(int first = 0; first < 10; ++first){
            for(int second = 0; second < 10; ++second){
                ans = add(ans, dp[n][first][second][5]);
            }
        }
        return ans;
    }
};
int main(){
	return 0;
}
