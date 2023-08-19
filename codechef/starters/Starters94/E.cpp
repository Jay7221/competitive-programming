#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    public:
        vector<int> tree;
        int n;
        SegmentTree(int n){
            int N = 1;
            while(N < n){
                N <<= 1;
            }
            this -> n = N;
            n = N;
            tree.assign(2 * n, 0);
        }
        void set(int ind, int val){
            ind += n;
            tree[ind] = val;
            ind /= 2;
            while(ind > 0){
                tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
                ind /= 2;
            }
        }
        int get(int l, int r){
            l += n;
            r += n;
            int ans = 0;
            while(l <= r){
                if((l & 1) == 1){
                    ans += tree[l];
                    ++l;
                }
                if((r & 1) == 0){
                    ans += tree[r];
                    --r;
                }
                l >>= 1;
                r >>= 1;
            }
            return ans;
        }
};
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n), x(n), y(n);
    map<int, vector<int>> mp;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    SegmentTree t(n);
    for(int i = 0; i < n; ++i){
        t.set(i, 1);
    }
    for(auto [a, v] : mp){
        for(int i : v){
            t.set(i, 0);
        }
        for(int i : v){
            x[i] = t.get(0, i - 1);
            y[i] = t.get(i + 1, n - 1);
        }
    }


    while(q--){
        int k, r;
        cin >> k >> r;
        --k, --r;
        int ans = 0;
        int d = x[k] + y[k] - r;
        if(d > 0){
            ans = (d + 1) / 2;
            ans = max(ans, d - x[k]);
            ans = max(ans, d - y[k]);
        }
        cout << ans << '\n';
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
