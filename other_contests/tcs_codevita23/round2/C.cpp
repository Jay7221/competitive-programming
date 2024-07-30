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
    string value;
    vector<Node> children;
    Node(){
        value = "code";
    }
    Node(string val){
        value = val;
    }
};

bool isVar(string s){
    return ((s.size() == 1) && ('A' <= s[0]) && (s[0] <= 'Z'));
}

class Parser{
public:
    map<string, int> table;
    Node readProgram(queue<string> &tokens){
        Node ans;
        while(!tokens.empty()){
            if(tokens.front() == "is"){
                Node cur("is");
                tokens.pop();

                cur.children.push_back(Node(tokens.front()));
                tokens.pop();

                if(tokens.front() == "Yes"){
                    tokens.pop();
                }
                cur.children.push_back(readProgram(tokens));


                if(tokens.front() == "No"){
                    tokens.pop();
                }
                cur.children.push_back(readProgram(tokens));

                tokens.pop();

                ans.children.push_back(cur);
            }
            else if(tokens.front() == "print"){
                Node cur("print");
                tokens.pop();

                cur.children.push_back(Node(tokens.front()));
                tokens.pop();

                ans.children.push_back(cur);
            }
            else if(isVar(tokens.front())){
                inputVariables(tokens);
            }
            else{
                return ans;
            }
        }
        return ans;
    }
    void inputVariables(queue<string> &tokens){
        vector<string> v;
        while(!tokens.empty()){
            v.push_back(tokens.front());
            tokens.pop();
        }
        int n = v.size() / 2;
        for(int i = 0; i < n; ++i){
            table[v[i]] = stoi(v[i + n]);
        }
    }
    bool eval(string s){
        string comp = s.substr(1, s.size() - 2);
        string A, B;
        A.push_back(s[0]);
        B.push_back(s.back());
        int a = table[A];
        int b = table[B];
        if(comp == ">"){
            return a > b;
        }
        else if(comp == "<"){
            return a < b;
        }
        else if(comp == "!="){
            return (a != b);
        }
        else{
            return (a == b);
        }
    }
    void evaluate(Node root, bool &prev){
        if(root.value == "code"){
            for(Node node: root.children){
                evaluate(node, prev);
            }
        }
        if(root.value == "is"){
            if(eval(root.children[0].value)){
                evaluate(root.children[1], prev);
            }
            else if(root.children.size() == 3){
                evaluate(root.children[2], prev);
            }
        }
        else if(root.value == "print"){
            if(prev){
                cout << '\n';
            }
            prev = true;
            cout << table[root.children[0].value];
        }
    }
};
void solve() {
    Parser p;
    queue<string> tokens;
    string tok;
    while(cin >> tok){
        tokens.push(tok);
    }
    Node root = p.readProgram(tokens);
    bool prev = false;
    p.evaluate(root, prev);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
