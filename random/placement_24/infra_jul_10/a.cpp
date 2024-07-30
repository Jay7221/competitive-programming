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
 
bool isSubseq(string a, string b){
    int i = 0;
    for(char ch: b){
        if(i == (int)a.size()){
            return true;
        }
        if(a[i] == ch){
            ++i;
        }
    }
    return (i == (int)a.size());
}
 
string getValidWord(string s, vector<string> dictionary){
    string res;
    for(string word: dictionary){
        if(isSubseq(word, s)){
            if(res.empty() || (res > word)){
                res = word;
            }
        }
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> dictionary(n);
    for(int i = 0; i < n; ++i){
        cin >> dictionary[i];
    }

    cout << getValidWord(s, dictionary);
    
    return 0;
}
 
