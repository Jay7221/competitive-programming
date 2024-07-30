/*
Author: Prajwal Shah
Language: C++
Third Year BTech IT
Walchand College of Engineering, Sangli
*/

//___________________//
#include <bits/stdc++.h>
#define pajju             main
#define Prajwal           ios_base::sync_with_stdio(false);
#define Shah              cin.tie(NULL);
#define ll                long long
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         (l + (h-l)/2)
#define fab(i, a, b)     for (auto i = a; i < b; ++i)
#define frab(i, a, b)    for (auto i = a; i >= b; --i)
#define mod               1000000007
#define ff                first
#define ss                second
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
//___________________//

using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void print(T t, V... v) {_print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


class DisjointSet{ public:

    vector<int> parent;

    DisjointSet(int n): parent(n) { for(int i=0; i<n; i++) parent[i] = i; }

    void join(int a, int b) { parent[find(b)] = find(a); }

    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

    bool check(int a, int b){ return find(a) == find(b); }
};

template <typename T>
class SGTree {
public:
    using SizeType = std::size_t;

    SizeType N;
    std::vector<T> seg;

    SGTree(SizeType _N) : N(_N), seg(_N * 4, T{}) {}

    void build(SizeType idx, SizeType low, SizeType high, const std::vector<T> &nums) {
        if (low == high) {
            seg[idx] = nums[low];
            return;
        }
        SizeType mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    T query(SizeType idx, SizeType low, SizeType high, SizeType l, SizeType r) {
        if (low > r || high < l)
            return T{};
        if (low >= l && high <= r)
            return seg[idx];
        SizeType mid = (low + high) / 2;
        T left = query(2 * idx + 1, low, mid, l, r);
        T right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(SizeType idx, SizeType low, SizeType high, SizeType index, T val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        SizeType mid = low + (high - low) / 2;
        if (index <= mid)
            update(2 * idx + 1, low, mid, index, val);
        else
            update(2 * idx + 2, mid + 1, high, index, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void sg_build(const std::vector<T> &nums) {
        build(0, 0, N - 1, nums);
    }

    T sg_query(SizeType l, SizeType r) {
        return query(0, 0, N - 1, l, r);
    }

    void sg_update(SizeType index, T val) {
        update(0, 0, N - 1, index, val);
    }
};

ll binPowWithModulo(ll base, ll n){
    ll res = 1;
    while(n != 0){
        if(n%2 == 1){
            res= (res*base)%mod;
            n--;
        }else{
            base= (base*base)%mod;
            n/=2;
        }
    }
    return res%mod ;
}


ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll inv(ll n, ll m){
    return binPowWithModulo(n, m-2);
}

ll C(ll n, ll r, ll m){
    if(r > n) return 0;
    ll res = 1;
    for(ll i = 1; i <= r; ++i){
        res = (res*(n-i+1))%m;
        res = (res*inv(i, m))%m;
    }
    return res;
}
vector<ll> seive(ll N){
    vector<ll>primes(N+1,1);
    primes[0] = primes[1] = 0;
    for(int i = 2; i*i <= N; ++i){
        if(primes[i] == 1){
            for(int j = i*i; j <= N; j+=i) primes[j] = 0;
        }
    }
    vector<ll>res;
    for(int i = 2; i <= N; ++i){
        if(primes[i]) res.pb(i);
    }
    return res;
}

vector<vector<ll>> findDivisors(ll N){
    vector<vector<ll>>divisors(N);
    for(int i = 1; i <= N; ++i){
        for(int j = i; j <= N; j += i){
            divisors[j].pb(i);
        }
    }
    return divisors;
}

vector<ll> findPrimeDivisors(ll N){
    vector<ll>res;
    for(int i = 2; i*i <= N; ++i){
        if(N%i == 0){
            res.pb(i);
            while(N%i == 0) N/=i;
        }
    }
    if(N != 1) res.pb(N);
    return res;
}

vector<ll> findPrimeDivisorsWithSieveOptimized(ll N){
    vector<ll>res;
    vector<ll>primes(N+1,1);
    primes[0] = primes[1] = 0;
    for(int i = 2; i*i <= N; ++i){
        if(primes[i] == 1){
            for(int j = i*i; j <= N; j+=i) primes[j] = 0;
        }
    }
    for(int i = 2; i <= N; ++i){
        if(primes[i] && N%i == 0){
            res.pb(i);
            while(N%i == 0) N/=i;
        }
        if(N == 1) break;
    }
    if(N != 1) res.pb(N);
    return res;
}

ll modmul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}

ll modadd(ll a, ll b){
    return ((a%mod)+(b%mod))%mod;
}

ll modsub(ll a, ll b){
    return ((a%mod)-(b%mod)+mod)%mod;
}

ll moddiv(ll a, ll b){
    return modmul(a, inv(b, mod));
}



void pr_binary(ll num){
    for(int i=10;i>=0;i--) cout<<((num>>i)&1);
    cout<<endl;
}

bool check_bit(ll a, ll i){
    if((a&(1<<i))!=0) return true;
    return false;
}

ll set_bit(ll a, ll i){
    return (a|(1<<i));
}

ll unset_bit(ll a, ll i){
    return (a&(~(1<<i)));
}

ll toggle_bit(ll a, ll i){
    return (a^(1<<i));
}

ll least_set_bit(ll a){
    return (a&(-a));
}

ll get_bit(ll a, ll i){
    return ((a>>i)&1);
}

ll count_setBits(ll a){
  ll ans=0;
  while(a){
    a=a&(a-1);
    ans++;
  }
  return ans;
}

void solve(){
    ll n,q; cin >> n;
    string s; cin >> s;
    vector<ll>a;
    for(int i = 0; i < n-1; ++i){
        a.pb(s[i] != s[i+1] ? 1 : 0);
    }
    if(a.empty()){
        while(q--){
            ll type, l, r; cin >> type >>  l >> r;
            if(type == 2){
                cout << "Yes\n";
            }
        }
        return;
    }
    SGTree<ll>sg(n);
    sg.sg_build(a);
  cin >> q;
    while(q--){
        ll type, l, r; cin >> type >>  l >> r;
        l--, r--;
        if(type == 1){
            if(l-1 >= 0){
                ll x = sg.sg_query(l-1, l-1);
                sg.sg_update(l-1,1-x);
            }
            if(r < n-1){
                ll x = sg.sg_query(r, r);
                sg.sg_update(r,1-x);
            }
        }else if(type == 2){
            ll x = sg.sg_query(l, r-1);

            cout << ((x == r - l) ? "Yes":"No") << "\n";
        }else{
            ll x = sg.sg_query(l, r-1);
            cout << ((x == 0) ? "Yes":"No") << "\n";
        }
    }

}
int pajju()
{
    // Prajwal Shah;
    solve();
    return 0;
}
