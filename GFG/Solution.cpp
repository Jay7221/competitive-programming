#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    void print(int u, int v)
    {
        cerr << "(" << u << ", " << v << ") ";
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
        bool indian[N][M], arabic[N][M];
        int n = N, m = M;
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                indian[i][j] = false;
                arabic[i][j] = false;
            }
        }
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i)
        {
            indian[i][m - 1] = true;
            arabic[i][0] = true;
            q.push({i, m - 1});
        }
        for(int i = 0; i < m; ++i)
        {
            indian[n - 1][i] = true;
            q.push({n - 1, i});
            arabic[0][i] = true;
        }
        vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(q.size())
        {
            int u, v;
            tie(u, v) = q.front();
            q.pop();
            for(int i = 0; i < d.size(); ++i)
            {
                int du, dv;
                tie(du, dv) = d[i];
                int uu = du + u, vv = dv + v;
                if((uu >= 0) && (uu < n) && (vv >= 0) && (vv < m))
                {
                    if(mat[uu][vv] >= mat[u][v])
                    {
                        if(!indian[uu][vv])
                        {
                            indian[uu][vv] = true;
                            q.push({uu, vv});
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            q.push({i, 0});
        }
        for(int i = 0; i < m; ++i)
        {
            q.push({0, i});
        }
        while(q.size())
        {
            int u, v;
            tie(u, v) = q.front();
            q.pop();
            for(int i = 0; i < d.size(); ++i)
            {
                int du, dv;
                tie(du, dv) = d[i];
                int uu = du + u, vv = dv + v;
                if((uu >= 0) && (uu < n) && (vv >= 0) && (vv < m))
                {
                    if(mat[uu][vv] >= mat[u][v])
                    {
                        if(!arabic[uu][vv])
                        {
                            arabic[uu][vv] = true;
                            q.push({uu, vv});
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                ans += indian[i][j] && arabic[i][j];
            }
        }
        return ans;
    }
};
int main()
{
	vector<vector<int>> mat = {{1, 3, 3, 2, 4},
               {4, 5, 6, 4, 4},
               {2, 4, 5, 3, 1},
               {6, 7, 1, 4, 5},
               {6, 1, 1, 3, 4}};
	Solution s;
	cout << s.water_flow(mat, mat.size(), mat[0].size()) << '\n';
}
