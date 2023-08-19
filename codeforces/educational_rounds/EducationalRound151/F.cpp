#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<class A, class B>
ostream& operator<<(ostream &out, const pair<A, B> &p){
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}
template<class A>
ostream& operator<<(ostream &out, const vector<A> &v){
    for(int i = 0; i < v.size(); ++i){
        if(i > 0){
            out << ' ';
        }
        out << v[i];
    }
    return out;
}
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

const int N = (1 << 19);
int mu[N], minD[N], ps[N];
ll mxk[N];
bool freq[N];
vector<cd> f(N), fn(N);
vector<int> divs[N];

void pre(){
    for(int d = 1; d < N; ++d){
        for(int v = d; v < N; v += d){
            divs[v].push_back(d);
        }
    }
    mu[1] = 1;
    for(int d = 2; d < N; ++d){
        if(minD[d] == 0){
            minD[d] = d;
        }
        if(minD[d] != minD[d / minD[d]]){
            mu[d] = - mu[d / minD[d]];
        }

        for(int v = 2 * d; v < N; v += d){
            if(minD[v] == 0){
                minD[v] = d;
            }
        }

    }
}
const int MOD = 1e9 + 7;
void solve(){
    int l, t;
    cin >> l >> t;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        freq[v[i]] = 1;
    }
    int MAX = *max_element(v.begin(), v.end());
    for(int i = 0; i < n; ++i){
        f[v[i]] = 1;
        fn[MAX - v[i]] = 1;
    }
    fft(f, false);
    fft(fn, false);
    for(int i = 0; i < N; ++i){
        f[i] = f[i] * f[i];
    }
    fft(f, true);
    for(int i = 0; i < N; ++i){
        int res = int(f[i].real() + 0.5);
        if(!(i & 1) && freq[i >> 1]){
            --res;
        }
        if(res > 0){
            ps[i] = 1;
        }
    }
    for(int i = 0; i < N; ++i){
        f[i] = freq[i];
    }
    fft(f, false);
    for(int i = 0; i < N; ++i){
        f[i] = f[i] * fn[i];
    }
    fft(f, true);
    for(int i = MAX + 1; i < N; ++i){
        int res = int(f[i].real() + 0.5);
        if(res > 0){
            ps[i - MAX] = 1;
        }
    }

    int ans = 0;
    for(int i = N - 1; i > 0; --i){
        if(ps[i] == 1){
            mxk[i] = max(mxk[i], (t * 1ll * i) / (2ll * l));
        }
        for(int d : divs[i]){
            ans = (ans + (mu[d] * (mxk[i] / d)) % MOD) % MOD;
            mxk[i / d] = max(mxk[i / d], mxk[i] / d);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();
    solve();

    return 0;
}
