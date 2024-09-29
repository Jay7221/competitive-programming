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
 
bool valid = true;
int precedence(char op){
    switch(op){
        case '+': return 1;
        case '-': return 4;
        case '*': return 2;
        case '/': return 3;
    }
    return 0;
}

int applyOp(int a, int b, char op){
    if((op == '/') && (b == 0)){
        valid = false;
        return -1;
    }
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    n = s.size();

    stack<int> values;
    stack<char> ops;

    valid = true;

    for(int i = 0; i < n; ++i){
        if(s[i] == ' '){
            continue;
        }
        else if(s[i] == '('){
            ops.push(s[i]);
        }
        else if(isdigit(s[i])){
            int val = 0;
            while((i < n) && (isdigit(s[i]))){
                val = 10 * val + (s[i] - '0');
                ++i;
            }
            values.push(val);
            --i;
        }
        else if(s[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
                if(!valid){
                    break;
                }
            }
            if(!ops.empty()){
                ops.pop();
            }
        }
        else{
            while(!ops.empty() && precedence(ops.top()) >= precedence(s[i])){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
                if(!valid){
                    break;
                }
            }
            ops.push(s[i]);
        }
    }
    if(!valid){
        cout << "INFINITY\n";
        return;
    }

    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    cout << values.top() << '\n';

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
 
