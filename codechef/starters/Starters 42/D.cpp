#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	auto print1 = [&](int a, int b){
		for(ll i = a; i < b + 1; i += 4){
			cout << (i * (i + 1)) << ' ' << ((i + 1) * (i + 3)) << ' ' << (i * (i + 2)) << ' ' << ((i + 3) * (i + 2)) << ' ';
		}
		cout << '\n';
	};
	auto print2 = [&](int a, int b){
		for(ll i = a; i < b + 1; i += 4){
			cout << (i * (i + 1)) << ' ' << ((i) * (i + 2)) << ' ' << ((i + 3) * (i + 2)) << ' ' << ((i + 3) * (i + 1)) << ' ';
		}
		cout << '\n';
	};
	if(n % 4 == 1){
		cout << '1' << ' ';
		print1(2, n);
	}else if(n % 4 == 2){
		cout << "1 2" << ' ';
		print2(3, n);
	}else if(n % 4 == 3){
		cout << "2 3 6" << ' ';
		print1(4, n);
	}else if(n % 4 == 0){
		print2(1, n);
	}
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