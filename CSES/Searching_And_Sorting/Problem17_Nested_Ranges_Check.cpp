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
  vector<int> pre(n), suf(n);
  for(int i = 0; i < n; ++i){
      int a, b, ind;
      tie(a, b, ind) = v[i];
      b = -b;
      pre[i] = b;
      if(i > 0){
          pre[i] = max(pre[i], pre[i - 1]);
      }
  }
  for(int i = n - 1; i >= 0; --i){
      int a, b, ind;
      tie(a, b, ind) = v[i];
      b = -b;
      suf[i] = b;
      if(i + 1 < n){
          suf[i] = min(suf[i], suf[i + 1]);
      }
  }
  vector<bool> isContained(n), contains(n);
  for(int i = 0; i < n; ++i){
      int a, b, ind;
      tie(a, b, ind) = v[i];
      b = -b;
      if(i > 0){
          isContained[ind] = (pre[i - 1] >= b);
      }
      if(i + 1 < n){
          contains[ind] = (suf[i + 1] <= b);
      }
  }
  for(int i = 0; i < n; ++i){
      cout << contains[i] << ' ';
  }
  cout << '\n';
  for(int i = 0; i < n; ++i){
      cout << isContained[i] << ' ';
  }
  cout << '\n';
}
