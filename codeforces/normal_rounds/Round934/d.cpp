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


class PalindromeChecker {
private:
    string processedString;
    vector<int> palindromicLengths;

    string preprocessString(const string& s) {
        string result = "#";
        for (char c : s) {
            result += c;
            result += "#";
        }
        return result;
    }

    void manacher() {
        int n = processedString.length();
        palindromicLengths.resize(n);

        int center = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            int mirror = 2 * center - i;

            if (i < right) {
                palindromicLengths[i] = min(right - i, palindromicLengths[mirror]);
            }

            // Expand around the current character
            int leftBound = i - (palindromicLengths[i] + 1);
            int rightBound = i + (palindromicLengths[i] + 1);
            while (leftBound >= 0 && rightBound < n && processedString[leftBound] == processedString[rightBound]) {
                palindromicLengths[i]++;
                leftBound--;
                rightBound++;
            }

            // Adjust center and right boundaries
            if (i + palindromicLengths[i] > right) {
                center = i;
                right = i + palindromicLengths[i];
            }
        }
    }

public:
    PalindromeChecker(const string& s) {
        processedString = preprocessString(s);
        manacher();
    }

    bool isPalindrome(int l, int r) {
        int n = processedString.size();
        if (l < 0 || r >= n || l > r) {
            return false; // Invalid range
        }
        int len = r - l + 1;
        int processedLeft = 2 * l + 1;
        int processedRight = 2 * r + 1;
        int processedCenter = (processedLeft + processedRight) / 2;
        int palindromicLength = palindromicLengths[processedCenter];

        if((l & 1) == (r & 1)){
            return len <= (palindromicLength + 1);
        }
        else{
            return len <= palindromicLength;
        }
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    PalindromeChecker pal(s);

    while(q--){
        int l, r;
        cin >> l >> r;
        --l, --r;
        auto get = [&](int len){
            if(len < 0){
                return 0ll;
            }
            if(len & 1){
                len = (len + 1) / 2;
                return (len * 1ll * len) - 1;
            }
            len >>= 1;
            return len * 1ll * (len + 1);
        };
        int len = r - l + 1;
        ll ans = 0;
        if(!pal.isPalindrome(l, r)){
            ans += get(r - l + 1);
        }
        else if(!pal.isPalindrome(l, r - 2) || !pal.isPalindrome(l + 1, r - 1) || !pal.isPalindrome(l + 2, r)){
            ans += get(r - l - 1);
        }

        if(!pal.isPalindrome(l, r - 1) || !pal.isPalindrome(l + 1, r)){
            ans += get(r - l);
        }

        cout << ans << '\n';
    }
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
 
