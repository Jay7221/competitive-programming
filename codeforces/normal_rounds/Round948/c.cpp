#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
ll solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll i = 0; i < n; ++i){
		cin >> a[i];
	}

	ll mx = *max_element(a.begin(), a.end());

	ll prod = 1;
	for(ll elem: a){
		prod = lcm(prod, elem);
		if(prod > mx){
			return n;
		}
	}

	ll ans = 0;

	auto evaluate = [&](ll x){
		ll ans = 0;
		ll l = 1;
		for(ll elem: a){
			if(elem == x){
				return 0ll;
			}
			if(x % elem == 0){
				++ans;
				l = lcm(l, elem);
			}
		}
		if(l != x){
			return 0ll;
		}
		return ans;
	};

	for(ll d = 1; d * d <= prod; ++d){
		if(prod % d == 0){
			ans = max(ans, evaluate(d));
			if(d * d != prod){
				ans = max(ans, evaluate(prod / d));
			}
		}
	}

	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
	    cout << solve() << '\n';
    }
    
    return 0;
}
 
