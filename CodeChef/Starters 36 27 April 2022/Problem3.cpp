#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)
void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n), odd, even;
	odd.reserve(n), even.reserve(n);
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] % 2){
			odd.push_back(a[i]);
		}else{
			even.push_back(a[i]);
		}
	}
	sort(odd.rbegin(), odd.rend());
	sort(even.rbegin(), even.rend());
	ll o = odd.size(), e = even.size();
	ll a_1 = 0, a_2 = 0;
	ll b_1 = 0, b_2 = 0;
	auto calc = [&](bool al, bool bob){
		bool go_a = 1, go_b;
		ll i = 0, j = 0;
		ll alice = 0, bo = 0;
	while(go_a || go_b){
		go_a = 0, go_b = 0;
		if(al){
			if(i < o){
				alice += odd[i];
				go_a = 1;
				i++;
			}
		}else{
			if(j < e){
				alice += even[j];
				go_a = 1;
				j++;
			}
		}
		if(bob){
			if(i < o){
				bo += odd[i];
				go_b = 1;
				i++;
			}
		}else{
			if(j < e){
				bo += even[j];
				go_b = 1;
				j++;
			}
		}
		// cerr << alice << ' ' << bo << '\n';
		al = go_a ^ al, bob = go_b ^ bob;
	}
	b_1 = alice, b_2 = bo;
	// cerr << b_1 << ' ' << b_2 << '\n';
};
// // calc(0, 1);
// calc(1, 1);
// a_1 = b_1, a_2 = b_2;
// calc(1, 0);
// if(b_2 > a_2)
// 	a_1 = b_1;
// if(a_2 == b_2)
// 	a_1 = max(a_1, b_1);

// // cerr << a_1 << '\n';
// calc(0, 1);
// if(a_1 < b_1){
// 	a_1 = b_1;
// 	a_2 = b_2;

// calc(0, 0);
// if(b_2 > a_2)
// 	a_1 = b_1;
// if(a_2 == b_2)
// 	a_1 = max(a_1, b_1);
// }
calc(1, 0);
ll p = b_1, q = b_2;
// a_1 = b_1;
// cerr << a_1 << '\n';
calc(1, 1);
if(q > b_2){
	a_1 = p;
}else if(q < b_2){
	a_1 = b_1;
}else{
	a_1 = max(b_1, p);
}
// cerr << a_1 << '\n';
ll ans = a_1;
calc(0, 0);
p = b_1, q = b_2;
calc(0, 1);
if(q > b_2){
	a_1 = p;
}else if(q < b_2){
	a_1 = b_1;
}else{
	a_1 = max(b_1, p);
}
ans = max(ans, a_1);
cout << ans << '\n';
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