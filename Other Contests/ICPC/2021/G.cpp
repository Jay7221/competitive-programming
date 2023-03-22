#include<bits/stdc++.h>
using namespace std;
const int FORBIDDEN = 101;
void print(vector<int> &v){
	for(int elem : v){
		cerr << elem << ' ';
	}
	cerr << '\n';
}
bool cmp(int a, int b){
	if((a > 100) || (b > 100)){
		return false;
	}
	if((a == 0) || (b == 0)){
		return true;
	}
	return (a == b);
}
vector<int> ZAlgo(vector<int> &v){
	int n = v.size();
	vector<int> dp(n);
	int l = 1, r = 0;
	for(int i = 1; i < n; ++i){
		if(i <= r){
			dp[i] = min(r - i + 1, dp[i - l]);
		}
		while((i + dp[i] < n) && cmp(v[dp[i]], v[i + dp[i]])){
			++dp[i];
		}
		if(r < dp[i]){
			l = i;
			r = dp[i];
		}
	}
	return dp;
}
vector<int> match(vector<int> &pattern, vector<int> &text){
	int m = pattern.size(), n = text.size();
	vector<int> v = pattern;
	v.push_back(FORBIDDEN);
	for(int elem : text){
		v.push_back(elem);
	}
	vector<int> z = ZAlgo(v);
	vector<int> ans;
	for(int i = 0; i < n; ++i){
		if(z[i + m + 1] == m){
			ans.push_back(i);
		}
	}
	return ans;
}
void solve(){
	int rp, cp, rq, cq;
	cin >> rp >> cp;
	int pat[rp][cp];
	for(int i = 0; i < rp; ++i){
		for(int j = 0; j < cp; ++j){
			cin >> pat[i][j];
		}
	}
	cin >> rq >> cq;
	int body[rq][cq];
	for(int i = 0; i < rq; ++i){
		for(int j = 0; j < cq; ++j){
			cin >> body[i][j];
		}
	}
	vector<int> text(rq * cq), pattern((rp - 1) * cq + cp);
	for(int i = 0; i < rq; ++i){
		for(int j = 0; j < cq; ++j){
			text[i * cq + j] = body[i][j];
		}
	}
	for(int i = 0; i < rp; ++i){
		for(int j = 0; j < cp; ++j){
			pattern[i * cq + j] = pat[i][j];
		}
	}
	vector<int> ans = match(pattern, text);
	int k = ans.size();
	cout << k << '\n';
	for(int coord : ans){
		cout << (1 + (coord / cq)) << ' ' << (1 + (coord % cq)) << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--){
		solve();
	}

	return 0;
}
