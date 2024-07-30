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

ll MOD = 1e9 + 7;
static const int MAX = 2e5 + 7;
vector<ll> fact, inv, invFact;
ll add(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    a = ((a % MOD) + MOD) % MOD;
    b = ((b % MOD) + MOD) % MOD;
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    a = ((a % MOD) + MOD) % MOD;
    ll ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}
ll divide(ll a, ll b){
    if(b < MAX){
        return mult(a, inv[b]);
    }
    return mult(a, power(b, MOD - 2));
}
ll com(ll a, ll b){
    if(a < b){
        return 0;
    }
    if(b < 0){
        return 0;
    }
    return divide(fact[a], mult(fact[a - b], fact[b]));
}
void pre(){
    fact = vector<ll>(MAX);
    inv= vector<ll>(MAX);
    invFact = vector<ll>(MAX);
    fact[0] = fact[1] = inv[1] = invFact[0] = invFact[1] = 1;
    for(int i = 2; i < MAX; ++i){
        ll q = MOD / i;
        ll r = MOD % i;
        inv[i] = mult(-q, inv[r]);
        fact[i] = mult(i, fact[i - 1]);
        invFact[i] = mult(inv[i], invFact[i - 1]);
    }
}

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

#define Hash pair<int, int>
 
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> cols(m, vector<int>(n));
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		for(int j = 0; j < m; ++j){
			cols[j][i] = s[j] - '0';
		}
	}

	auto get_hash = [&](vector<int> &flip){
		MOD = MOD1;
		int ans1 = 0;
		for(int i = 0; i < n; ++i){
			ans1 = add(ans1, mult(flip[i], power(2, i)));
		}
		MOD = MOD2;
		int ans2 = 0;
		for(int i = 0; i < n; ++i){
			ans2 = add(ans2, mult(flip[i], power(2, i)));
		}
		Hash ans = {ans1, ans2};
		return ans;
	};

	auto flip_hash = [&](Hash hash, vector<int> &flip, int i){
		int hash1, hash2;
		tie(hash1, hash2) = hash;
		int new_hash1, new_hash2;

		new_hash1 = add(hash1, mult(power(2, i), sub(1, 2 * flip[i])));
		new_hash2 = add(hash2, mult(power(2, i), sub(1, 2 * flip[i])));
		Hash new_hash = {new_hash1, new_hash2};
		return new_hash;
	};

	map<Hash, int> freq;
	for(vector<int> &col: cols){
		vector<int> flip = col;
		Hash hash = get_hash(flip);
		for(int i = 0; i < n; ++i){
			Hash new_hash = flip_hash(hash, flip, i);
			++freq[new_hash];
		}
	}
	int ans = 0;
	Hash target_hash = {-1, -1};
	for(auto [u, f]: freq){
		if(ans < f){
			ans = f;
			target_hash = u;
		}
	}
	vector<int> target_flip;
	for(vector<int> &col: cols){
		vector<int> flip = col;
		Hash hash = get_hash(flip);
		for(int i = 0; i < n; ++i){
			Hash new_hash = flip_hash(hash, flip, i);
			if(new_hash == target_hash){
				target_flip = flip;
				target_flip[i] ^= 1;
				break;
			}
		}
	}
	cout << ans << '\n';
	for(int elem: target_flip){
		cout << elem;
	}
	cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
