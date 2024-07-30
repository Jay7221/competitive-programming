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
 
bool query(int i, int j){
	++i, ++j;
	cout << "? " << i << ' ' << j << endl;
	string res;
	cin >> res;
	return (res == "YES");
}

void answer(vector<int> &colors){
	cout << "! ";
	for(int elem: colors){
		cout << elem << ' ';
	}
	cout << endl;
}
void solve() {
	int n;
	cin >> n;

	int white = n, black = n - 1;
	stack<int> red;
	vector<int> color(n + 1);

	color[n - 1] = 1;

	for(int i = n - 2; i > 0; --i){
		if(red.empty()){
			if(!query(i, black)){
				white = i;
			}
			else if(!query(i, white)){
				black = i;
			}
			else{
				red.push(i);
			}
		}
		else{
			if(query(i, red.top())){
				red.push(i);
			}
			else{
				if(query(i, white)){
				}
				else{
				}
			}
		}
	}

	reverse(color.begin(), color.end());
	color.pop_back();
	reverse(color.begin(), color.end());

	answer(color);
}
 
int main() {
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
