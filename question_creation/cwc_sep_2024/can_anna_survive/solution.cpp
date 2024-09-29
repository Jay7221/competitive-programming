#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n;
  ll x, y;
  cin >> n >> x >> y;
  ll a[n];
  for(int i = 0; i < n; ++i){
	cin >> a[i];
  }
  ll minCost = a[0] + a[1];
  for(int i = 1; i < n; ++i){
	minCost = min(minCost, (a[i - 1] + a[i]));
  }
  if(x < y + minCost){
	cout << "No\n";
  }
  else{
	cout << "Yes\n";
  }
  return 0;
}
