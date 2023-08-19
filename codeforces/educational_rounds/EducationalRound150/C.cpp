#include<bits/stdc++.h>
using namespace std;
#define ll long long
int power(int a, int p){
    int ans = 1;
    for(int i = 0; i < p; ++i){
        ans *= a;
    }
    return ans;
}
ll eval(vector<int> a){
    reverse(a.begin(), a.end());
    int mx = -1;
    ll ans = 0;
    for(int elem : a){
        if(mx > elem){
            ans -= power(10, elem);
        }else{
            ans += power(10, elem);
            mx = elem;
        }
    }
    return ans;
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        a[i] = (s[i] - 'A');
    }
    ll ans = eval(a);

    for(int k = 0; k < 5; ++k){
        for(int i = 0; i < n; ++i){
            if(a[i] == k){
                for(int j = 0; j < 5; ++j){
                    int tmp = a[i];
                    a[i] = j;
                    ans = max(ans, eval(a));
                    a[i] = tmp;
                }
                break;
            }
        }
        for(int i = n - 1; i >= 0; --i){
            if(a[i] == k){
                for(int j = 0; j < 5; ++j){
                    int tmp = a[i];
                    a[i] = j;
                    ans = max(ans, eval(a));
                    a[i] = tmp;
                }
                break;
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
