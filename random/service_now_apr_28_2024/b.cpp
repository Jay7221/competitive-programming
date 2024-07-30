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
 
vector<int> getSubFolders(vector<vector<string>> &existingStructure, vector<vector<string>> &queries){
    map<string, int> ind;
    vector<string> value;
    vector<vector<int>> adj;
    vector<bool> active;

    auto add_folder_name = [&](string s){
        if(ind.find(s) == ind.end()){
            ind[s] = value.size();
            value.push_back(s);
            adj.push_back(vector<int>());
            active.push_back(true);
        }
    };
    auto remove_folder_name = [&](string s){
        if(ind.find(s) != ind.end()){
            active[ind[s]] = false;
            ind.erase(s);
        }
    };

    for(auto edge: existingStructure){
        for(string s: edge){
            add_folder_name(s);
        }
    }

    for(auto edge: existingStructure){
        int u = ind[edge[0]];
        int v = ind[edge[1]];
        adj[u].push_back(v);
    }

    function<void(int)> remove_dir = [&](int u){
        remove_folder_name(value[u]);
        for(int v: adj[u]){
            remove_dir(v);
        }
    };
    function<int(int)> count_dir = [&](int u){
        if(!active[u]){
            return 0;
        }
        int ans = 1;
        for(int v: adj[u]){
            ans += count_dir(v);
        }
        return ans;
    };

    vector<int> ans;
    for(auto q: queries){
        string type = q[0];
        if(type == "mkdir"){
            string x = q[1];
            string y = q[2];
            add_folder_name(y);
            adj[ind[x]].push_back(ind[y]);
        }
        else if(type == "rmdir"){
            string x = q[1];
            remove_dir(ind[x]);
        }
        else{
            string x = q[1];
            ans.push_back(count_dir(ind[x]));
        }
    }
    return ans;
}

class Folder{
    string name;
    vector<Folder*> children;
public:
    Folder(string s){
        name = s;
    }
    bool is(string s){
        return (name == s);
    }
    void createSubdir(string s){
        children.push_back(new Folder(s));
    }
};

vector<int> getSubFolders2(vector<vector<string>> &existingStructure, vector<vector<string>> &queries){
    vector<int> ans;
    Folder *root = new Folder("folder-1");
    return ans;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<string>> existingStructure(n);
    vector<vector<string>> queries(q);
    for(int i = 0; i < n; ++i){
        string u, v;
        cin >> u >> v;
        existingStructure[i].push_back(u);
        existingStructure[i].push_back(v);
    }
    for(int i = 0; i < q; ++i){
        string cmd;
        cin >> cmd;
        string a, b;

        queries[i].push_back(cmd);
        if(cmd == "mkdir"){
            cin >> a >> b;
            queries[i].push_back(a);
            queries[i].push_back(b);
        }
        else if(cmd == "rmdir"){
            cin >> a;
            queries[i].push_back(a);
        }
        else if(cmd == "count_subdir"){
            cin >> a;
            queries[i].push_back(a);
        }
    }
    for(int elem: getSubFolders2(existingStructure, queries)){
        cout << elem << '\n';
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
 
