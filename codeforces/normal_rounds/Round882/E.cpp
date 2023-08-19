#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B, typename C> ostream& operator<<(ostream &os, const tuple<A, B, C> &p) {A a; B b; C c; tie(a, b, c) = p; return os << '(' << a << ", " << b << ", " << b << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
void pre(){
    map<int, vector<vector<int>>> mp;
    for(int a = 1; a <= 4; ++a){
        for(int b = a; b <= 4; ++b){
            for(int c = b; c <= 4; ++c){
                int area = (a + b + c) * (a + b - c) * (a - b + c) * (-a + b + c);
                vector<int> points = {a, b, c};
                area = max(area, 0);
                mp[area].push_back(points);
            }
        }
    }
}
 
int getArea(int a, int b, int c){
    return max(0, ( ( a + b + c ) * ( a + b - c ) * ( a - b + c ) * ( -a + b + c) ));
}
int query(int i, int j, int k){
    ++i, ++j, ++k;
    cout << "? " << i << " " << j << " " << k << endl;
    int s;
    cin >> s;
    return s;
}
void answer(vector<int> a){
    cout << "! ";
    if(a.size() == 0){
        cout << -1;
    }else{
        for(int elem : a){
            cout << elem << " ";
        }
    }
    cout << endl;

}
void nextArray(vector<int> &a){
    for(int i = 0; i < a.size(); ++i){
        if(a[i] < 4){
            ++a[i];
            for(int j = 0; j < i; ++j){
                a[j] = 1;
            }
            return;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    cerr << "Hello World"<< endl;
    if(n < 9){
        vector<int> a;
        vector<int> b(n, 1);
        int cnt = 0;
        vector<vector<vector<int>>> q(n, vector<vector<int>>(n, vector<int>(n)));
        vector<int> ans = {1, 2, 3, 4};
        auto check = [&](){
            for(int i = 0; i < n; ++i){
                for(int j = i + 1; j < n; ++j){
                    for(int k = j + 1; k < n; ++k){
                        if(getArea(b[i], b[j], b[k]) != q[i][j][k]){
                            return false;
                        }
                    }
                }
            }
            return true;
        };
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                for(int k = j + 1; k < n; ++k){
                    q[i][j][k] = query(i, j, k);
                }
            }
        }
        for(int i = 0; i < (1 << (2 * n)); ++i){
            if(check()){
                a = b;
                ++cnt;
            }
            nextArray(b);
        }
        if(cnt != 1){
            a.clear();
        }
        answer(a);

    }else{
        int ind1, ind2;
        int val;
        vector<int> arr(n);
        vector<bool> vis(n);
        auto set = [&](){
            for(int i = 0; i < 9; ++i){
                for(int j = i + 1; j < 9; ++j){
                    for(int k = j + 1; k < 9; ++k){
                        int q = query(i, j, k);
                        for(int v = 1; v <= 4; ++v){
                            if(getArea(v, v, v) == q){
                                ind1 = i, ind2 = j, val = v;
                                return;
                            }
                        }
                    }
                }
            }
        };
        auto set2 = [&](vector<int> &ind){
            for(int i = 0; i < ind.size(); ++i){
                for(int j = i + 1; j < ind.size(); ++j){
                    int q = query(ind[i], ind[j], ind1);
                    for(int v = 1; v <= 4; ++v){
                        if(getArea(val, v, v) == q){
                            i = ind[i];
                            j = ind[j];

                            ind1 = i, ind2 = j;
                            val = v;
                            arr[ind1] = arr[ind2] = val;
                            vis[ind1] = vis[ind2] = true;
                            ind.clear();
                            return;
                        }
                    }
                }
            }
        };
        set();
        arr[ind1] = arr[ind2] = val;
        vis[ind1] = vis[ind2] = true;

        if(val == 1){
            vector<int> indices;
            for(int i = 0; i < n; ++i){
                if(vis[i]){
                    continue;
                }
                if(query(ind1, ind2, i) == 0){
                    indices.push_back(i);
                    if(indices.size() == 4){
                        break;
                    }
                }else{
                    vis[i] = true;
                    arr[i] = 1;
                }
            }
            set2(indices);
            if(indices.size() > 0){
                arr.clear();
                answer(arr);
                return;
            }
        }

        for(int i = 0; i < n; ++i){
            if(vis[i]){
                continue;
            }
            int q = query(ind1, ind2, i);
            for(int c = 1; c <= 4; ++c){
                if(q == getArea(val, val, c)){
                    arr[i] = c;
                }
            }
        }
        answer(arr);
    }
}
 
int main() {
    pre();
    solve();
    
    return 0;
}
 
