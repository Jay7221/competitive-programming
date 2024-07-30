/*
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
 
vector<int> allMEX_failed(int N, vector<int> A){
    int maxMEX = 0;
    sort(A.begin(), A.end());
    for(int i = 0; i < N; ++i){
        if(A[i] > i){
            break;
        }
        maxMEX = i + 1;
    }

    vector<int> ans;
    for(int i = 0; i <= maxMEX; ++i){
        ans.push_back(i);
    }
    return ans;
}

vector<int> allMEX(int N, vector<int> A){
    int mex = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int elem: A){
        pq.push(elem);
    }

    while(!pq.empty() && (pq.top() <= mex)){
        ++mex;
        pq.pop();
    }

    vector<int> ans;
    for(int i = 0; i <= mex; ++i){
        ans.push_back(i);
    }
    return ans;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int elem: allMEX(n, a)){
        cout << elem << '\n';
    }
}
 
int main1() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
*/
 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int mex = 0;
    for(int elem: a){
        if(elem > mex){
            break;
        }
        ++mex;
    }

    for(int i = 0; i <= mex; ++i){
        cout << i << '\n';
    }

    return 0;
}
