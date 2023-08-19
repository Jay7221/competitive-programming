import java.util.*;
import java.lang.Math.*;
class Solution
{
	public int maxInstance(String s)
	{
		int[] freq = new int[26];
		for(int i = 0; i < s.length(); ++i)
		{
			int cur = s.charAt(i) - 'a';
			++freq[cur];
		}
		int ans = s.length();
		ans = Math.min(ans, freq['b' - 'a']);
		ans = Math.min(ans, freq['a' - 'a']);
		ans = Math.min(ans, freq['l' - 'a'] / 2);
		ans = Math.min(ans, freq['o' - 'a'] / 2);
		ans = Math.min(ans, freq['n' - 'a']);
		return ans;
	}
}
class Ballons_Everywhere
{
	public static void main(String args[])
	{
		Solution sol = new Solution();
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		System.out.println(sol.maxInstance(str));
	}
}
