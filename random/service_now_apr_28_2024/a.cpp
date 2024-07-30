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
 
string makeLexicographicallySmallestPalindrome(string s){
    vector<int> freq(26);
    for(char ch: s){
        ++freq[ch - 'a'];
    }

    deque<int> v;
    for(int i = 0; i < 26; ++i){
        if(freq[i] & 1){
            v.push_back(i);
            --freq[i];
        }
    }

    string left, mid;

    while((int)v.size() > 1){
        freq[v.front()] += 2;
        v.pop_front();
        v.pop_back();
    }
    if(!v.empty()){
        mid.push_back('a' + v.front());
    }

    for(int i = 0; i < 26; ++i){
        while(freq[i] > 0){
            freq[i] -= 2;
            left.push_back(i + 'a');
        }
    }

    string ans = left + mid;
    reverse(left.begin(), left.end());
    ans += left;

    return ans;
}
 
void solve() {
    string s;
    cin >> s;
    cout << makeLexicographicallySmallestPalindrome(s) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        solve();
    }
    
    return 0;
}
 
