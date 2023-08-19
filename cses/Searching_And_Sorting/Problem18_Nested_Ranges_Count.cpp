#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int main(){
	int n;
	cin >> n;
  vector<tuple<int, int, int>> v(n);
  for(int i = 0; i < n; ++i){
      int a, b;
      cin >> a >> b;
      v[i] = {a, -b, i};
  }
  sort(v.begin(), v.end());
  vector<int> isContained(n, 1), contains(n, 1);

  set<int> st;
  map<int, int> dp;
  // dp[r] = number of ranges [l, r] ending at r or above
  for(auto [l, r, ind] : v){
      r = -r;
      if(st.lower_bound(r) != st.end()){
          int rr = *st.lower_bound(r);
          isContained[ind] += dp[rr];
      }
      dp[r] = isContained[ind];
      st.insert(r);
  }
  st.clear();
  dp.clear();
  for(int i = n - 1; i >= 0; --i){
      int l, r, ind;
      tie(l, r, ind) = v[i];
      r = -r;
      contains[ind] = n - 1 - i;
      if(st.upper_bound(r) != st.end()){
          int rr = st.upper_bound(r);
          contains[ind] -= dp[rr];
      }
      dp[r] = n - 1 - contains[ind];
      st.insert(r);
  }

  for(int i = 0; i < n; ++i){
      --contains[i];
      cout << contains[i] << ' ';
  }
  cout << '\n';
  for(int i = 0; i < n; ++i){
      --isContained[i];
      cout << isContained[i] << ' ';
  }
  cout << '\n';
}
