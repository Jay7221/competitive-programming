#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (int)(2500 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 2);
	vector<vector<bool> > pre(n + 2, vector<bool>(mx)), suf(n + 2, vector<bool>(mx));
	for(int i = 1; i < n + 1; ++i)
		cin >> a[i];
	for(int i = 0; i < n + 2; ++i){
		pre[i][0] = 1, suf[i][0] = 1;
	}
	for(int i = 1; i < n + 1; ++i){
		for(int j = 0; j < mx; ++j){
			pre[i][j] = (pre[i][j] | pre[i - 1][j]);
			if(j >= a[i]){
				pre[i][j] = (pre[i][j] | pre[i - 1][j - a[i]]);
			}
		}
	}
	for(int i = n; i > 0; --i){
		for(int j = 0; j < mx; ++j){
			suf[i][j] = (suf[i][j] | suf[i + 1][j]);
			if(j >= a[i]){
				suf[i][j] = (suf[i][j] | suf[i + 1][j - a[i]]);
			}
		}
	}
	int total = accumulate(a.begin(), a.end(), 0);
	auto getans = [&](int ind){
		int req = (total - a[ind]) / 2;
		int k = 0;
		int j = req;
		for(int i = 0; i < req + 1; ++i){
			if(!pre[ind - 1][i])
				continue ;
			while(i + j > req)
				--j;
			while(j > 0 && !suf[ind + 1][j])
				--j;
			if(pre[ind - 1][i] && suf[ind + 1][j])
				k = max(k, i + j);
		}
		k += a[ind] ;
		return k;
	};
	int ans = getans(1);
	int ind = 1;
	for(int i = 1; i < n; ++i){
		int tmp = getans(i);
		if(tmp > ans){
			ans = tmp;
			ind  = i;
		}
	}
	vector<int> A, B;
	auto construct = [&](int ind){
		vector<int> pos(mx), last(mx);
		pos[0] = 1;
		int sumi = 0;
		int req = (total - a[ind]) / 2;
		for(int i = 1; i < n + 1; ++i){
			if(i == ind)
				continue ;
			for(int j = sumi; j >= 0; --j){
				if(!pos[j])
					continue ;
				if(!pos[a[i] + j]){
					pos[a[i] + j] = 1;
					last[a[i] + j] = i;
				}
			}
			sumi += a[i];
		}
		vector<bool> used(n + 2);
		A.push_back(ind);
		while(!pos[req])
			--req;
		while(req > 0){
			A.push_back(last[req]);
			used[last[req]] = 1;
			req -= a[last[req]];
		}
		for(int i = 1; i < n + 1; ++i){
			if(!used[i] && i != ind)
				B.push_back(i);
		}
	};
	construct(ind);
	vector<int> C;
	int sum1 = 0, sum2 = 0;
	// sum1 = chefu's wealth, sum2 = chefa's wealth
	// cur = the net surplus that chefu has over chefa
	while(sum1 + sum2 < total){
		// cerr << sum1 << ' ' << sum2 << '\n';
		// debug(A)
		// debug(B)
		if(sum1 <= sum2){
			int ind = A.back();
			A.pop_back();
			C.push_back(ind);
			sum1 += a[ind];
		}else{
			int ind = B.back();
			B.pop_back();
			C.push_back(ind);
			sum2 += a[ind];
		}
	}
	for(auto c : C){
		cerr << a[c]
		cout << c << ' ';
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
}