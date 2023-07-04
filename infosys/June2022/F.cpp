#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e4 + 7;
vector<bool> isPrime(MAX, true);
void pre(){
    for(int i = 2; i < MAX; ++i){
        if(isPrime[i]){
            for(int j = 2; i * j < MAX; ++j){
                isPrime[i * j] = false;
            }
        }
    }
}
void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    priority_queue<int> pq;
    for(int i = 0; i < n; ++i){
        if(isPrime[a[i]]){
            pq.push(a[i]);
        }
        if(b[i] == 1){
            if(pq.size()){
                ans += pq.top();
                pq.pop();
            }
        }
    }

    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();
    solve();

    return 0;
}
