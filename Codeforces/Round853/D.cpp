#include<bits/stdc++.h>
using namespace std;
#define ll long long
void printAns(vector<int> &ans){
	cout << ans.size() << '\n';
	for(int elem : ans){
		cout << elem << ' ';
	}
	cout << '\n';
}
void print(vector<bool> &v){
	for(int elem : v){
		cerr << elem;
	}
	cerr << '\n';
}
bool pre(vector<bool> &a, vector<bool> &b){
	int n = a.size();
	if(a == b){
		cout << 0 << '\n';
		return true;
	}
	if(count(b.begin(), b.end(), 0) == n){
		cout << -1 << '\n';
		return true;
	}
	if(count(a.begin(), a.end(), 0) == n){
		cout << -1 << '\n';
		return true;
	}
	return false;
}
void solve(){
	int n;
	cin >> n;
	vector<bool> a(n), b(n);
	for(int i = 0; i < n; ++i){
		char ch;
		cin >> ch;
		a[i] = ch -'0';
	}
	for(int i = 0; i < n; ++i){
		char ch;
		cin >> ch;
		b[i] = ch - '0';
	}
	if(pre(a, b)){
		return;
	}
	vector<int> ans;
	auto check =[&](int ind){
		return ((ind >= 0) && (ind < n));
	};
	auto shift = [&](int k){
		ans.push_back(k);
		if(k > 0){
			for(int i = 0; i < n; ++i){
				if(check(i + k)){
					a[i] = (a[i] ^ a[i + k]);
				}
			}
		}
		else{
			for(int i = n - 1; i >= 0; --i){
				if(check(i + k)){
					a[i] = (a[i] ^ a[i + k]);
				}
			}
		}
	};
	auto lowBit = [&](vector<bool> &v){
		for(int i = 0; i < n; ++i){
			if(v[i] == 1){
				return i;
			}
		}
		return 0;
	};
	auto highBit = [&](vector<bool> &v){
		for(int i = n - 1; i >= 0; --i){
			if(v[i] == 1){
				return i;
			}
		}
		return 0;
	};
	int ha = highBit(a), lb = lowBit(b);
	if(ha < lb){
		shift(ha - lb);
	}
	ha = highBit(a);
	for(int i = lb; i >= 0; --i){
		if(a[i] != b[i]){
			shift(ha - i);
		}
	}
	for(int i = lb + 1; i < n; ++i){
		if(a[i] != b[i]){
			shift(lb - i);
		}
	}
	printAns(ans);
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