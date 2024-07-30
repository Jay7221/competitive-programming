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
 
 
bool solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<bool> pre(n, true), suf(n, true);
	for(int i = 2; i < n; ++i){
		int b1 = gcd(a[i - 1], a[i - 2]);
		int b2 = gcd(a[i], a[i - 1]);
		pre[i] = pre[i - 1] && (b1 <= b2);
	}
	for(int i = n - 3; i >= 0; --i){
		int b1 = gcd(a[i], a[i + 1]);
		int b2 = gcd(a[i + 1], a[i + 2]);
		suf[i] = suf[i + 1] && (b1 <= b2);
	}
	if(suf[1] || pre[n - 2]){
		return true;
	}

	for(int i = 1; i < n - 1; ++i){
		bool ok = pre[i - 1] && suf[i + 1];
		int b = gcd(a[i - 1], a[i + 1]);
		if(i > 1){
			int prev = gcd(a[i - 2], a[i - 1]);
			ok &= (prev <= b);
		}
		if(i + 2 < n){
			int next = gcd(a[i + 1], a[i + 2]);
			ok &= (b <= next);
		}
		if(ok){
			return true;
		}
	}

	return false;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
	    if(solve()){
		    cout << "YES\n";
	    }
	    else{
		    cout << "NO\n";
	    }
    }
    
    return 0;
}
 
