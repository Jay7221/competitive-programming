import java.util.*;
class Solution2{
	int water_flow(int [][] mat, int N, int M) {
		boolean arabic[][] = new boolean[N][M];
		boolean indian[][] = new boolean[N][M];
		ArrayList<Integer> q = new ArrayList<Integer>();
		for(int i = 0; i < N; ++i)
		{
			q.add(i * N + M - 1);
		}
		for(int i = 0; i < M; ++i)
		{
			q.add(N * (N - 1) + i);
		}
		while(q.size() > 0)
		{
			int u = q.front();
			q.pop();
		}
		return 0;
	}
	public static void main(String args[])
	{
	}
}
