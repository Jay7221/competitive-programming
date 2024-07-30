ll add(ll a, ll b, ll mod){
    a = ((a % mod) + mod) % mod;
    b = ((b % mod) + mod) % mod;
    return ((a + b) % mod);
}
ll sub(ll a, ll b, ll mod){
    a = ((a % mod) + mod) % mod;
    b = ((b % mod) + mod) % mod;
    return (((a - b) % mod + mod) % mod);
}
ll mult(ll a, ll b, ll mod){
    a = ((a % mod) + mod) % mod;
    b = ((b % mod) + mod) % mod;
    return ((a * b) % mod);
}
ll power(ll a, ll p, ll mod){
    a = ((a % mod) + mod) % mod;
    ll ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a, mod);
        }
        a = mult(a, a, mod);
        p >>= 1;
    }
    return ans;
}
ll divide(ll a, ll b, ll mod){
    return mult(a, power(b, mod - 2, mod),mod);
}

string process(string s){
    string s_processed;
    ll cnt = 0;
    char prev = '$';
    for(char ch: s){
        if(ch != prev){
            if(cnt > 0){
                if(cnt & 1){
                    s_processed.push_back(prev);
                }
                else{
                    s_processed.push_back(prev);
                    s_processed.push_back(prev);
                }
            }
            cnt = 0;
            prev = ch;
        }
        ++cnt;
    }
    if(cnt & 1){
                s_processed.push_back(prev);
    }
    else{
                s_processed.push_back(prev);
                s_processed.push_back(prev);
    }
    return s_processed;
}

class HashString{
    ll n;
    vector<ll> pre, suf;
    ll mod;
public:
    HashString(string s, ll mod){
        this -> mod = mod;
        n = s.size();
        pre.resize(n);
        suf.resize(n);
        for(ll i = 0; i < n; ++i){
            pre[i] = (s[i] - '0');
            suf[i] = (s[i] - '0');
        }
        for(ll i = 1; i < n; ++i){
            pre[i] = add(pre[i - 1], mult(pre[i], power(2, i, mod), mod), mod);
        }
        for(ll i = n - 2; i >= 0; --i){
            suf[i] = add(suf[i + 1], mult(suf[i], power(2, n - 1 - i, mod), mod), mod);
        }
    }
    ll get_hash(ll l, ll r){
        --l;
        ll ans = pre[r];
        if(l >= 0){
            ans = sub(ans, pre[l], mod);
            ans = divide(ans, power(2, l + 1, mod), mod);
        }
        return ans;
    }
    ll get_rev_hash(ll l, ll r){
        ++r;
        ll ans = suf[l];
        if(r < n){
            ans = sub(ans, suf[r], mod);
            ans = divide(ans, power(2, n - r, mod), mod);
        }
        return ans;
    }
};

