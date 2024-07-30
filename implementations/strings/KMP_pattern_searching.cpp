vector<int> stringMatch(string text, string pattern) {
	int n = text.size();
	int m = pattern.size();
	vector<int> lps(m);
	int len = 0;
	for(int i = 1; i < m; ++i){
		while((len > 0) && pattern[i] != pattern[len]){
			len = lps[len - 1];
		}
		if(pattern[i] == pattern[len]){
			++len;
			lps[i] = len;
		}
	}
	int i = 0, j = 0;
	vector<int> ans;
	while(i < n){
		if(j == m){
			ans.push_back(i - m);
			j = lps[j - 1];
		}else{
			if(text[i] == pattern[j]){
				++i, ++j;
			}else{
				if(j > 0){
					j = lps[j - 1];
				}else{
					++i;
				}
			}
		}
	}
    if(j == m){
        ans.push_back(i - m);
    }
	return ans;
}
