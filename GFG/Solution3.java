class Solution3{
	static int n;
	static int arr[];
	static boolean vis[], isGood[];
	static void dfs(int u)
	{
		vis[u] = true;
		int v = u + arr[u];
		if((v < 0) || (v > n - 1))
		{
			isGood[u] = true;
		}
		else
		{
			if(!vis[v])
			{
				dfs(v);
			}
			if(isGood[v])
			{
				isGood[u] = true;
			}
			else
			{
				isGood[u] = false;
			}
		}
	}
	public static int goodStones(int N, int[] A) {
	    n = N;
	    arr = A;
	    vis = new boolean[n];
	    isGood = new boolean[n];
	    for(int i = 0; i < n; ++i)
	    {
		    if(!vis[i])
		    {
			    dfs(i);
		    }
	    }
	    int ans = 0;
	    for(int i = 0; i < n; ++i)
	    {
		    if(isGood[i])
		    {
			    ++ans;
		    }
	    }
	    return ans;
	}
	public static void main(String args[])
	{
	    int n = 7;
	    int arr[] = new int[]{2, 3, -1, 2, -2, 4, 1};
	    System.out.println(goodStones(n, arr));
	}
}
