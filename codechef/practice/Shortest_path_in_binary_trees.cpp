#include <bits/stdc++.h>
using namespace std;
#define debug(a) for(int i = 0; i < a.size(); i++){cerr << a[i] << ' ';} cerr << '\n';
#define vi vector<int>
#define ll long long 
int dist(int i, int j){
	int x = max(i, j);
	int y = min(i, j);
	int ans = 0;
	while(x ^ y > y){
		ans++;
		x = x >> 1;
		if(ans > 100){
			break ;
		}
	}
	ans += abs(x - y) * 2;
	return ans;
}
void solve(){
	int n;
	cin >> n;
	while(n--){
		int i, j;
		cin >> i >> j;
		cout << dist(i, j) << '\n';
	}
}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}