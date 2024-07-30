#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  int k;
  cin >> k;
  int ans = 0;
  int first_mx = -1;
  multiset<int> st;
  for(int elem : a){
    st.insert(elem);
  }
  for(int i = 0; i < n - 1; ++i){
    st.erase(st.find(a[i]));
    first_mx = max(first_mx, a[i]);
    int second_mn = *st.begin();
    if(first_mx + second_mn >= k){
      ++ans;
    }
  }
  if(ans == 0){
    ans = -1;
  }
  cout << ans;
}
 
int main() {
  solve();
  return 0;
}
 
