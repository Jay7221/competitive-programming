#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct SegmentTree{
    int n;
    vector<int> tree;
    SegmentTree(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree.assign(2 * n, 0);
    }
    void set(int ind, int val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    int get(int x, int node = 1){
        // return the first index i, such that s[i] < x
        int ans = 1;
        while(ans < n){
            ans <<= 1;
            if(tree[ans] >= x){
                ++ans;
            }
        }
        return (ans - n);
    }
};
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(n + 1);
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        queries[r].push_back(l);
    }

    vector<int> dp(n + 1);
    SegmentTree s(n + 1);
    for(int i = 1; i <= n; ++i){
        s.set(a[i], i);
        dp[i] = dp[i - 1];
        for(auto l : queries[i]){
            int res = s.get(l);
            dp[i] = max(dp[i], res + dp[l - 1]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
