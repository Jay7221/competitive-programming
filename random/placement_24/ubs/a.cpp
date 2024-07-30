#include<bits/stdc++.h>
using namespace std;
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
long getNumberOfDroppedPackets(vector<vector<int>> &requests, int max_packets, int rate){
    long ans = 0;
    sort(requests.begin(), requests.end());

    long curTime = 0;
    long remPackets = 0;

    for(vector<int> &request: requests){
        int t = request[0];
        int p = request[1];

        remPackets = max(0l, remPackets - rate * (t - curTime)) + p;
        curTime = t;

        if(remPackets > max_packets){
            ans += remPackets - max_packets;
            remPackets = max_packets;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int size;
    cin >> size;
    vector<vector<int>> requests(n, vector<int>(size));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2; ++j){
            cin >> requests[i][j];
        }
    }
    int max_packets;
    cin >> max_packets;
    int rate;
    cin >> rate;
    cout << getNumberOfDroppedPackets(requests, max_packets, rate) << '\n';
    return 0;
}
