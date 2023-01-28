#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<vector<map<ll, int> > > dp(n, vector<map<ll, int>>(2));
        for(int i = n - 2; i > -1; --i){
            for(int j = i + 1; j < n; ++j){
                ll diff = (ll)nums[j] - (ll)nums[i];
                ++dp[i][0][diff];
                if(dp[j][0].find(diff) != dp[j][0].end()){
                    dp[i][1][diff] += dp[j][0][diff];
                }
                if(dp[j][1].find(diff) != dp[j][1].end()){
                    dp[i][1][diff] += dp[j][1][diff];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(auto [u, f] : dp[i][1]){
                ans += f;
            }
        }
        return ans;
    }
};
