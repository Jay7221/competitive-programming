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
 
vector<int> primes;
const int MAX = 1e6 + 7;
void pre(){
    vector<bool> isPrime(MAX, true);
    for(int p = 2; p < MAX; ++p){
        if(isPrime[p]){
            primes.push_back(p);
            for(int j = 2; p * j < MAX; ++j){
                isPrime[j * p] = false;
            }
        }
    }
}

vector<ll> primeFactors(ll x){
    vector<ll> pFactors;
    for(int p: primes){
        if(p > x){
            break;
        }
        if(x % p == 0){
            pFactors.push_back(p);
            while(x % p == 0){
                x /= p;
            }
        }
    }
    if(x > 1){
        pFactors.push_back(x);
    }
    return pFactors;
}

vector<ll> calcPreCost(vector<int> &a, int l, int r){
    // Calculate the cost pre[i] = cost to move all element from 0 to i to i
    int len = r - l + 1;
    vector<ll> cost(len);
    ll pre = a[l];
    for(int i = 1; i < len; ++i){
        cost[i] = cost[i - 1] + pre;
        pre += a[i + l];
    }
    return cost;
}

vector<ll> calcSufCost(vector<int> &a, int l, int r){
    // Calculate the cost suf[i] = cost to move all element from i to n - 1 to i
    int len = r - l + 1;
    vector<ll> cost(len);
    ll suf = a[r];
    for(int i = len - 2; i >= 0; --i){
        cost[i] = cost[i + 1] + suf;
        suf += a[i + l];
    }
    return cost;
}

ll costForD(ll d, vector<int> a){
    // Calculate the cost to make all elements of a multiples of d, given that the total sum of a is multiple of d
    for(int &elem: a){
        elem %= d;
    }
    int n = a.size();
    ll totCost = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == 0){  // already a multiple of d
            continue;
        }

        // Find the smallest array starting at i with sum d
        int j = i;
        ll cur = a[i];
        while(cur != 0){
            ++j;
            cur = (cur + a[j]) % d;
        }

        // i to j has sum d
        vector<ll> preCost = calcPreCost(a, i, j);
        vector<ll> sufCost = calcSufCost(a, i, j);

        int len = preCost.size();

        // Calcuate the cost to move all values to k for k = i, ...., j
        ll minCost = preCost[0] + sufCost[0];   // make a[i] = d
        for(int k = 1; k < len; ++k){
            minCost = min(minCost, preCost[k] + sufCost[k]);        // the cost to take make a[i + k] equal to d
        }

        totCost += minCost;
        i = j;
    }
    return totCost;
}
 
ll solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll tot = accumulate(a.begin(), a.end(), 0ll);
    if(tot == 1){
        return -1;
    }

    ll minCost = tot * n;

    for(int p: primeFactors(tot)){
        minCost = min(minCost, costForD(p, a));
    }

    return minCost;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();
    cout << solve() << '\n';
    
    return 0;
}
 
