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
        Node* children[10];
        int freq = 0;
};

vector<int> runeNumber = {
    2, 2, 2, 
    3, 3, 3, 
    4, 4, 4, 
    5, 5, 5, 
    6, 6, 6, 
    7, 7, 7, 7, 
    8, 8, 8, 
    9, 9, 9, 9
};

class Trie{
    private:
        Node* root;

    public:
        Trie(){
            root = new Node();
        }

        void insertName(string name){
            Node* cur = root;
            for(char ch: name){
                int rune = runeNumber[ch - 'a'];
                if(!cur -> children[rune]){
                    cur -> children[rune] = new Node();
                }
                cur = cur -> children[rune];
                ++cur -> freq;
            }
        }

        int getNumberNames(string rune){
            Node* cur = root;
            for(char ch: rune){
                cur = cur -> children[ch - '0'];
                if(!cur){
                    return 0;
                }
            }
            return cur -> freq;
        }
};
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> names(n), runes(m);
    for(int i = 0; i < n; ++i){
        cin >> names[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> runes[i];
    }

    Trie trie;
    for(string name: names){
        trie.insertName(name);
    }

    for(string rune: runes){
        cout << trie.getNumberNames(rune) << '\n';
    }

}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
