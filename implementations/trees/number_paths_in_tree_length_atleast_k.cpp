ll getNumPaths(vector<vector<int>> &adj, int k){
    int n = adj.size();
    vector<vector<int>> paths(n);
    ll ans = 0;
    function<void(int, int)> dfs;
    dfs = [&dfs, &paths, &adj, &n, &k, &ans](int u, int p){
        for(int v : adj[u]){
            if(v == p){
                continue;
            }
            dfs(v, u);
            if(paths[v].size() > paths[u].size()){
                swap(paths[u], paths[v]);
            }
            for(int i = 0; i < paths[v].size(); ++i){
                // the depth of paths at index i is paths[v].size() - i, since we add one for coming above
                int depth = paths[v].size() - i;
                // cnt is number of paths with depth = depth
                ll cnt = paths[v][i];
                if(i > 0){
                    cnt -= paths[v][i - 1];
                }
                // Now we want paths of length >= k with highest node u
                // So assume some part of path has length depth
                // Now we want the other part having length k - depth
                // It will be at depth (k - depth)
                // search for nodes with exactly (k - depth) depth
                int req_depth = k - depth;
                if(req_depth > 0){
                    int req_index = paths[u].size() - req_depth;
                    if((req_index >= 0) && (req_index < paths[u].size())){
                        ll tmp = cnt * paths[u][req_index];
                        ans += tmp;
                    }
                    else{
                        break;
                    }
                }
                else{
                    ans += cnt * paths[u].back();
                }
            }
 
            // merge paths[v] with paths[u]
            for(int i = 0; i < paths[v].size(); ++i){
                int depth = paths[v].size() - i;
                int ind = paths[u].size() - depth;
                paths[u][ind] += paths[v][i];
            }
        }
        // Now consider all paths that end exactly at u
        // Such paths will have depth of atleast k
        int req_index = paths[u].size() - k;
        if((req_index >= 0) && (req_index < paths[u].size())){
            ll tmp = paths[u][req_index];
            ans += tmp;
        }
 
        // Now we will add path consisting of zero depth, or an empty path
        if(paths[u].size() > 0){
            paths[u].push_back(1 + paths[u].back());
        }else{
            paths[u].push_back(1); 
        }
    };
    dfs(0, -1);
    return ans;
}

