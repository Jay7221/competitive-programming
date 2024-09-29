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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }

    vector<int> freq(n), rem(n);
    vector<bool> isLast(n);
    vector<vector<int>> ind(n);

    for(int i = n - 1; i >= 0; --i){
        if(rem[a[i]] == 0){
            isLast[i] = true;
        }
        ++rem[a[i]];
        ind[a[i]].push_back(i);
    }

    int l = 0;

    set<int> st;
    vector<int> res;
    vector<bool> vis(n);

    auto add = [&](int elem){
        if(vis[elem]){
            return;
        }
        if(freq[elem] == 0){
            st.insert(elem);
        }
        ++freq[elem];
    };

    auto remove = [&](int elem){
        if(vis[elem]){
            return;
        }
        --freq[elem];
        ind[a[l]].pop_back();
        if(freq[elem] == 0){
            st.erase(elem);
        }
    };

    auto operate = [&](){
        int elem;
        if(res.size() & 1){
            // Minimize next elem
            elem = *st.begin();
        }
        else{
            // Maximize next elem
            elem = *(--st.end());
        }

        st.erase(elem);
        vis[elem] = true;
        res.push_back(elem);

        int r = ind[elem].back();
        while(l <= r){
            remove(a[l]);
            ++l;
        }

    };

    for(int i = 0; i < n; ++i){
        if(vis[a[i]]){
            continue;
        }
        add(a[i]);
        if(isLast[i]){
            while(!vis[a[i]]){
                operate();
            }
        }
    }

    cout << res.size() << '\n';
    for(int elem: res){
        cout << elem + 1 << ' ';
    }
    cout << '\n';
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
 
