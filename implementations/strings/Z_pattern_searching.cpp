vector<int> zFunction(const string& s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}


vector<int> search(string s, string pattern) {
    vector<int> ans;
    string zs = pattern + "$" + s;
    vector<int> z = zFunction(zs);
    int p = pattern.size(), n = s.size();
    for(int i = p + 1; i < (n + p + 1); ++i){
        if(z[i] == p){
            ans.push_back(i - (p + 1));
        }
    }
    return ans;
}
