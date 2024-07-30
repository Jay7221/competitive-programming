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
int gcd(int a, int b){
    while(b > 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
const int INF = 1e9 + 7;
struct GCDSegmentTree{
    int f(int a, int b){
    return gcd(a, b);
    }
    vector<int> tree;
    int n;
    void init(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree = vector<int>(2 * n);
    }
    GCDSegmentTree(){
    }
    GCDSegmentTree(int sz){
        init(sz);
    }
    GCDSegmentTree(vector<int> &arr){
        int sz = arr.size();
        init(sz);
        for(int i = 0; i < sz; ++i){
            tree[i + n] = arr[i];
        }
        for(int i = n - 1; i > 0; --i){
            tree[i] = f(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void set(int ind, int val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = f(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    int get(int l, int r){
        l += n;
        r += n;
        int res = 0;
        while(l <= r){
            if((l & 1) == 1){
                res = f(res, tree[l]);
                ++l;
            }
            if((r & 1) == 0){
                res =  f(res, tree[r]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};
struct MinSegmentTree{
    int f(int a, int b){
        return min(a, b);
    }
    vector<int> tree;
    int n;
    void init(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree = vector<int>(2 * n);
    }
    MinSegmentTree(){
    }
    MinSegmentTree(int sz){
        init(sz);
    }
    MinSegmentTree(vector<int> &arr){
        int sz = arr.size();
        init(sz);
        for(int i = 0; i < sz; ++i){
            tree[i + n] = arr[i];
        }
        for(int i = n - 1; i > 0; --i){
            tree[i] = f(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void set(int ind, int val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = f(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    int get(int l, int r){
        l += n;
        r += n;
        int res = INF;
        while(l <= r){
            if((l & 1) == 1){
                res = f(res, tree[l]);
                ++l;
            }
            if((r & 1) == 0){
                res =  f(res, tree[r]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};
 
void solve() {
  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  GCDSegmentTree gtree(a);
  vector<ll> pre(n + 1);
  for(int i = 1; i <= n; ++i){
    pre[i] = a[i] + pre[i - 1];
  }

  vector<int> c(n + 1);
  for(int i = 1; i <= n; ++i){
    cin >> c[i];
  }

  vector<int> cost(n + 1, INF);
  cost[1] = c[1];
  MinSegmentTree ctree(cost);
  cost[1] = 0;

  auto get_l = [&](int ind){
    int l = 1, r = ind;
    while(l < r){
      int mid = (l + r) / 2;
      if(gtree.get(mid, ind) < y){
        l = mid + 1;
      }
      else{
        r = mid;
      }
    }
    return l;
  };
  auto get_r = [&](int ind){
    int l = 1, r = ind - 1;
    while(l < r){
      int mid = (l + r + 1) / 2;
      ll diff = pre[ind] - pre[mid - 1];
      if(diff < x){
        r = mid - 1;
      }
      else{
        l = mid;
      }
    }
    return l;
  };
  for(int i = 2; i <= n; ++i){
    int l = get_l(i);
    int r = get_r(i);
    if(l <= r){
      cost[i] = ctree.get(l, r);
      if(cost[i] != INF){
        ctree.set(i, cost[i] + c[i]);
      }
    }
  }
  int ans = cost[n];
  if(ans == INF){
    ans = -1;
  }
  cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
