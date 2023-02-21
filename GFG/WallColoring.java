class Solution{
	int minCost(int [][] colors, int N){
		int INF = 1000000007;
		int[][] dp = new int[N][3];
		for(int i = 1; i < N; ++i)
		{
			for(int k = 0; k < 3; ++k)
			{
				dp[i][k] = INF;
			}
		}
		for(int k = 0; k < 3; ++k)
		{
			dp[0][k] = colors[0][k];
		}
		for(int i = 1; i < N; ++i)
		{
			for(int k = 0; k < 3; ++k)
			{
				for(int c = 0; c < 3; ++c)
				{
					if(c != k)
					{
						dp[i][k] = Math.min(dp[i][k], dp[i - 1][c] + colors[i][k]);
					}
				}
			}
		}
		int ans = INF;
		for(int k = 0; k < 3; ++k)
		{
			ans = Math.min(ans, dp[N - 1][k]);
		}
		return ans;
	}
}
public class WallColoring
{
	public static void main(String args[])
	{
		Solution s = new Solution();
		int [][] colors = new int[][]{{14, 2, 11},
             {11, 14, 5},
             {14, 3, 10}};
		System.out.println(s.minCost(colors, 3));
	}
}
