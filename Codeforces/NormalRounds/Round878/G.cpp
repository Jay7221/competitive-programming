#include<bits/stdc++.h>
using namespace std;
#define ll long long
int query1(int k){
    cout << "+ " << k << endl;
    int result;
    cin >> result;
    return result;
}
int query2(int k){
    cout << "- " << k << endl;
    int result;
    cin >> result;
    return result;
}
void answer(int n){
    cout << "! " << n << endl;
}
void solve(){
    int x;
    cin >> x;
    int n = x;
    int diff = 1000;
    while(true){
        x = query1(diff);
        if(x <= n){
            break;
        }
        n = x;
    }
    for(int i = 0; i <= diff; ++i){
        int px = x;
        x = query1(n + i);
        if(x == px){
            n += i;
            break;
        }
    }
    answer(n);
}
void pre(){
    int MAX = 1e6;
    ++MAX;
    vector<bool> isPrime(MAX, true);
    isPrime[0] = false;
    for(int i = 2; i < MAX; ++i){
        if(isPrime[i]){
            for(int j = 2; i * j < MAX; ++j){
                isPrime[i * j] = false;
            }
        }
    }
    int cnt = accumulate(isPrime.begin(), isPrime.end(), 0);
    cout << cnt << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();

    return 0;
}
