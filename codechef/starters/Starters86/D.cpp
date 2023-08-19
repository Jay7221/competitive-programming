#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e6 + 7;
vector<bool> isPrime(MAX, true);
vector<int> primes;
void pre(){
	for(int i = 2; i < MAX; ++i){
		if(isPrime[i]){
			primes.push_back(i);
			for(int j = 2; i * j < MAX; ++j){
				isPrime[i * j] = false;
			}
		}
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int d = a[0];
	for(int elem : a){
		d = gcd(d, elem);
	}
	auto factorize = [&](int n){
		vector<int> ans;
		for(int p : primes){
			if(p * p > n){
				break;
			}
			if(n % p == 0){
				ans.push_back(p);
				while(n % p == 0){
					n /= p;
				}
			}
		}
		if(n > 1){
			ans.push_back(n);
		}
		return ans;
	};
	vector<int> ans;
	if(d == 1){
		vector<bool> vis(m + 1);
		for(int elem : a){
			for(int p : factorize(elem)){
				vis[p] = true;
			}
		}
		bool flag = true;
		for(int p : primes){
			if(p > m){
				break;
			}
			if(!vis[p]){
				ans.push_back(p);
				flag = false;
				break;
			}
		}
		if(flag){
			ans.push_back(2);
			ans.push_back(3);
		}
	}


	else{
		for(int elem : a){
			if(elem != d){
				ans.push_back(d);
				break;
			}
		}
	}


	cout << ans.size() << '\n';
	for(int elem : ans){
		cout << elem << ' ';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pre();

	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
