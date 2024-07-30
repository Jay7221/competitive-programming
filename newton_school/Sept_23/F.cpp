#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
// Use mt19937_64 for 64 bit random numbers.
 
const ll MAX = 1e6 + 7;
vector<ll> primes;
void pre(){
  vector<bool> isPrime(MAX, true);
  for(ll p = 2; p < MAX; ++p){
    if(isPrime[p]){
      primes.push_back(p);
      for(ll j = 2; j * p < MAX; ++j){
        isPrime[j * p] = false;
      }
    }
  }
}
 void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
void solve() {
  ll m;
  cin >> m;
  vector<ll> a(m);
  for(ll i = 0; i < m; ++i){
    cin >> a[i];
  }
  map<ll, ll> freq;
  for(ll elem : a){

    for(ll p : primes){
      while(elem % p == 0){
        elem /= p;
        ++freq[p];
      }
    }

    ll l = sqrt(elem) - 10;
    l = max(l, 2ll);
    ll r = sqrt(elem) + 10;
    for(ll p = l; p <= r; ++p){
      while(elem % p == 0){
        elem /= p;
        ++freq[p];
      }
    }

    if(elem > 1){
      ++freq[elem];
    }
  }

  ll k_max = 0;
  ll no_primes = 0;

  for(auto [p, k] : freq){
    if(k > k_max){
      k_max = k;
      no_primes = 0;
    }
    if(k == k_max){
      ++no_primes;
    }
  }
  __int128 ans = 1;
  while(no_primes--){
    ans <<= 1;
  }
  --ans;
  if(k_max == 0){
    ans = -1;
  }
  cout << k_max << '\n';
  print(ans);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
  pre();
  solve();
    
    return 0;
}
 
