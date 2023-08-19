vector<int> getZ(string s){
    int n = s.size();
    vector<int> z(n);
    int l = 1;
    for(int i = 1; i < n; ++i){
        z[i] = z[i - l];
        while((i + z[i] < n) && (s[i + z[i]] == s[z[i]])){
            ++z[i];
        }
        if((i + z[i]) >= (l + z[l])){
            l = i;
        }
    }
    return z;
}
vector<int> search(string s, string pattern) {
    vector<int> ans;
    string zs = pattern + "$" + s;
    vector<int> z = getZ(zs);
    int p = pattern.size(), n = s.size();
    for(int i = p + 1; i < (n + p + 1); ++i){
        if(z[i] == p){
            ans.push_back(i - (p + 1));
        }
    }
    return ans;
}
