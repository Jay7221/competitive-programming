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
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}

	vector<vector<int>> b(n, vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> b[i][j];
		}
	}

	auto apply = [&](vector<int> &v, vector<int> &f){
		int sz = f.size();
		vector<bool> vis(sz);
		for(int i = 0; i < sz; ++i){
			int cur = i;
			if(!vis[cur]){
				vector<int> tmp;
				while(!vis[cur]){
					tmp.push_back(cur);
					vis[cur] = true;
					cur = f[cur];
				}
				for(int i = 1; i < (int)tmp.size(); ++i){
					swap(v[tmp[i - 1]], v[tmp[i]]);
				}
			}
		}
	};
	auto get_perm = [&](vector<int> v){
		vector<pair<int, int>> ind;
		for(int i = 0; i < (int)v.size(); ++i){
			ind.push_back({v[i], i});
		}
		vector<int> p;
		sort(ind.begin(), ind.end());
		for(auto [val, ind]: ind){
			p.push_back(ind);
		}
		return p;
	};

	vector<int> pa;
	for(int i = 0; i < n; ++i){
		if(count(a[i].begin(), a[i].end(), 1) > 0){
			pa = get_perm(a[i]);
			break;
		}
	}
	for(int i = 0; i < n; ++i){
		apply(a[i], pa);
	}

	vector<int> pb;
	for(int i = 0; i < n; ++i){
		if(count(b[i].begin(), b[i].end(), 1) > 0){
			pb = get_perm(b[i]);
			break;
		}
	}
	for(int i = 0; i < n; ++i){
		apply(b[i], pb);
	}

	vector<vector<int>> ra(m, vector<int>(n));
	vector<vector<int>> rb(m, vector<int>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			ra[j][i] = a[i][j];
			rb[j][i] = b[i][j];
		}
	}

	pa = get_perm(ra[0]);
	pb = get_perm(rb[0]);
	for(int i = 0; i < m; ++i){
		apply(ra[i], pa);
		apply(rb[i], pb);
	}


	return (ra == rb);
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
 
