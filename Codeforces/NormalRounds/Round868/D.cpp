#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> x(k), c(k);
	for(int i = 0; i < k; ++i){
		cin >> x[i];
		--x[i];
	}
	for(int i = 0; i < k; ++i){
		cin >> c[i];
	}
	bool isPossible = true;
	if(c[0] > x[0] + 1){
		isPossible = false;
	}
	for(int i = 1; i < k; ++i){
		if((c[i] - c[i - 1]) > (x[i] - x[i - 1])){
			isPossible = false;
		}
	}
	if(!isPossible){
		cout << "NO\n";
		return;
	}
	vector<char> v(n, '$');
	for(int i = 0; i < c[0]; ++i){
		v[i] = 'a';
	}
	v[c[0] - 2] = 'b';
	v[c[0] - 1] = 'c';
	char cur_char = 'd';
	for(int i = 1; i < k; ++i){
		int cnt = c[i] - c[i - 1];
		for(int j = x[i - 1] + 1; cnt > 0; --cnt, ++j){
			v[j] = cur_char;
		}
		++cur_char;
	}
	cur_char = 'a';
	for(int i = 0; i < n; ++i){
		if(v[i] == '$'){
			v[i] = cur_char;
			cur_char = 'a' + ((1 + (cur_char - 'a')) % 3);
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; ++i){
		cout << v[i];
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