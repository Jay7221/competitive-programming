#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, s1, s2;
	cin >> n >> s1 >> s2;
	vector<int> a, b;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		int r;
		cin >> r;
		v[i] = {r, i + 1};
	}
	sort(v.rbegin(), v.rend());

	
	int cur1 = s1, cur2 = s2;
	for(auto [r, i] : v){
		if(cur1 <= cur2){
			cur1 += s1;
			a.push_back(i);
		}else{
			cur2 += s2;
			b.push_back(i);
		}
	}


	cout << a.size() << ' ';
	for(int elem : a){
		cout << elem << ' ';
	}
	cout << '\n';
	cout << b.size() << ' ';
	for(int elem : b){
		cout << elem << ' ';
	}
	cout << '\n';
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
