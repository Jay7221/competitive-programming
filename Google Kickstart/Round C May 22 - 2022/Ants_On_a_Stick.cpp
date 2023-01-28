#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, l;
	cin >> n >> l;
	vector<int> left, right;
	vector<pair<int, int> > ants(n);
	for(int i = 0; i < n; ++i){
		int p, d;
		cin >> p >> d;
		ants[i] = {p, i + 1};
		if(d == 0){
			left.push_back(p);
		}else{
			right.push_back(l - p);
		}
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	vector<pair<int, int> > time;
	sort(ants.begin(), ants.end());
	for(auto c : right){
		int cur = ants.back().second;
		time.push_back({c, cur});
		ants.pop_back();
	}
	for(int i = 0; i < ants.size(); ++i){
		time.push_back({left[i], ants[i].second});
	}
	sort(time.begin(), time.end());
	for(auto c : time)
		cout << c.second << ' ' ;
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; ++i){
		cout << "Case #" << i << ": ";
		solve();
	}
}