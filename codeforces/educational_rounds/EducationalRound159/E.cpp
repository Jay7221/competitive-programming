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
 
class Node{
public:
    int freq = 0;
    Node* child[26];
};

class Trie{
public:

    Node* root;

    int totalLen = 0;

    Trie(){
        root = new Node();
    }

    void add(string s){
        totalLen += s.size();
        Node *cur = root;
        for(char ch : s){
            int c = ch - 'a';
            if(cur -> child[c] == NULL){
                cur -> child[c] = new Node();
            }
            cur = cur -> child[c];
        }
        ++(cur -> freq);
    }

    void dfs(){
        dfs(root);
    }
    void dfs(Node* root){
        for(int i = 0; i < 26; ++i){
            if(root -> child[i] != NULL){
                dfs(root -> child[i]);
                root -> freq += root -> child[i] -> freq;
            }
        }
    }

    ll get(string s){
        reverse(s.begin(), s.end());

        int len = s.size();
        Node* cur = root;
        ll ans = len * 1ll * (cur -> freq) + totalLen;

        for(char ch : s){
            int c = ch - 'a';
            cur = cur -> child[c];
            --len;

            if(cur == NULL){
                break;
            }

            ans -= 2 * cur -> freq;
        }

        return ans;
    }
};
 
void solve() {
    int n;
    cin >> n;
    string s[n];
    Trie trie;

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        trie.add(s[i]);
    }
    trie.dfs();
    for(int i = 0; i < n; ++i){
        ans += trie.get(s[i]);
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
