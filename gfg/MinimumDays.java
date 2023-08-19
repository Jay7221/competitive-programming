import java.util.*;
class Solution {
    public static int getMinimumDays(int N, String S, int[] P) {
	    int[] indexOf = new int[N];
	    for(int i = 0; i < N; ++i)
	    {
		    indexOf[P[i]] = i + 1;
	    }
	    int ans = 0;
	    for(int i = 1; i < N; ++i)
	    {
		    if(S.charAt(i - 1) == S.charAt(i))
		    {
			    ans = Math.max(ans, Math.min(indexOf[i], indexOf[i - 1]));
		    }
	    }
	    return ans;
    }
}
class MinimumDays{
	public static void main(String args[])
	{
		int n;
		String s;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		s = sc.next();
		int[] p = new int[n];
		for(int i = 0; i < n; ++i)
		{
			p[i] = sc.nextInt();
		}
		System.out.println(Solution.getMinimumDays(n, s, p));
	}
}
