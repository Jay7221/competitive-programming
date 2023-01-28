#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 7;
const int inf = 1e9 + 7;
void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  vector<int> M(mx);
  for(int i = 0; i < n; ++i){
    int prev_mn = inf;
    for(int j = 1; j < min(a[i], k) + 1; j = a[i] / (a[i] / j) + 1){
      int cur_mn = a[i] / j;
      M[cur_mn + 1] = max(M[cur_mn + 1], prev_mn);
      prev_mn = cur_mn;
    }
    M[0] = max(M[0], prev_mn);
  }
  for(int i = 1; i < mx; ++i){
    M[i] = max(M[i], M[i - 1]);
  }
  int ans = inf;
  for(int i = 0; i < a[0] + 1; ++i){
    ans = min(ans, M[i] - i);
  }
  cout << ans << '\n';
}
int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}