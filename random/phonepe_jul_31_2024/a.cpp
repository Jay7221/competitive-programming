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
 
 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    int mn = 0;
    int mx = 0;

    for(int i = 0; i < n; ++i){
        int minLit = count(s[i].begin(), s[i].end(), '1');
        int rem = m / 4;
        int cnt = 0;
        for(char ch: s[i]){
            if(ch == '1'){
                ++cnt;
                if(cnt == 2){
                    cnt = 0;
                    if(rem > 0){
                        --minLit;
                        --rem;
                    }
                }
            }
            else{
                cnt = 0;
            }
        }

        int maxLit = 0;

        stack<char> st;
        rem = m / 4;
        for(char ch: s[i]){
            if(ch == '1'){
                if(!st.empty() && (st.top() == '0') && (rem > 0)){
                    st.pop();
                    --rem;
                    ++maxLit;
                }
                else{
                    st.push(ch);
                }
            }
            else{
                if(!st.empty() && (rem > 0)){
                    if(st.top() == '1'){
                        ++maxLit;
                    }
                    st.pop();
                    --rem;
                }
                else{
                    st.push(ch);
                }
            }
        }

        while(rem--){
            ++maxLit;
            st.pop();
            st.pop();
        }

        for(int i = 0; i < m / 2; ++i){
            maxLit += (st.top() == '1');
            st.pop();
        }


        mn += minLit;
        mx += maxLit;
    }
    
    cout << mn << ' ' << mx << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
