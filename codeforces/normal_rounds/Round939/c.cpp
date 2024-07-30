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
 
void print(vector<vector<int>> &a){
    for(auto v: a){
        cerr << v << '\n';
    }
    cerr << "--------\n";
}
int solve1(int n) {
    vector<vector<int>> a(n, vector<int>(n, 0));

    auto get_sum = [&](){
        int sum = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                sum += a[i][j];
            }
        }
        return sum;
    };

    auto row_sum = [&](int row){
        int sum = 0;
        for(int col = 0; col < n; ++col){
            sum += a[row][col];
        }
        return sum;
    };

    auto col_sum = [&](int col){
        int sum = 0;
        for(int row = 0; row < n; ++row){
            sum += a[row][col];
        }
        return sum;
    };

    vector<pair<int, int>> operations;
    auto operate = [&](int type, int ind){
        operations.push_back({type, ind});
        if(type == 1){
            for(int col = 0; col < n; ++col){
                a[ind][col] = col + 1;
            }
        }
        else{
            for(int row = 0; row < n; ++row){
                a[row][ind] = row + 1;
            }
        }

    };

    int s = (n * (n + 1)) / 2;

    bool isrow = true;
    bool flag = true;

    while(flag){
        flag = false;
        if(isrow){
            for(int i = 0; i < n; ++i){
                if(row_sum(i) < s){
                    operate(1, i);
                    flag = true;
                }
            }
        }
        else{
            for(int i = 0; i < n; ++i){
                if(col_sum(i) <= s){
                    operate(2, i);
                    flag = true;
                }
            }
        }
        isrow ^= 1;
    }

    print(a);



    cout << get_sum() << ' ' << operations.size() << '\n';
    for(auto [type, ind]: operations){
        cout << type << ' ' << ind + 1 << ' ';
        for(int i = 1; i <= n; ++i){
            cout << i << ' ';
        }
        cout << '\n';
    }

    return get_sum();
}
 
int solve(int n) {
    vector<vector<int>> a(n, vector<int>(n, 0));

    auto get_sum = [&](){
        int sum = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                sum += a[i][j];
            }
        }
        return sum;
    };

    auto row_sum = [&](int row){
        int sum = 0;
        for(int col = 0; col < n; ++col){
            sum += a[row][col];
        }
        return sum;
    };

    auto col_sum = [&](int col){
        int sum = 0;
        for(int row = 0; row < n; ++row){
            sum += a[row][col];
        }
        return sum;
    };

    vector<pair<int, int>> operations;
    auto operate = [&](int type, int ind){
        operations.push_back({type, ind});
        if(type == 1){
            for(int col = 0; col < n; ++col){
                a[ind][col] = col + 1;
            }
        }
        else{
            for(int row = 0; row < n; ++row){
                a[row][ind] = row + 1;
            }
        }

    };

    for(int i = n - 1; i >= 0; --i){
        operate(1, i);
        operate(2, i);
    }

    cout << get_sum() << ' ' << operations.size() << '\n';
    for(auto [type, ind]: operations){
        cout << type << ' ' << ind + 1 << ' ';
        for(int i = 1; i <= n; ++i){
            cout << i << ' ';
        }
        cout << '\n';
    }

    return get_sum();
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;
        solve(n);
    }
    
    return 0;
}
 
