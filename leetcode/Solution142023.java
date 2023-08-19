import java.util.*;
class Solution142023{
    static public String addBinary(String a, String b) {
	    StringBuilder aa = new StringBuilder(a);
	    StringBuilder bb = new StringBuilder(b);
	    if(aa.length() < bb.length())
	    {
		    StringBuilder tmp = aa;
		    aa = bb;
		    bb = tmp;
	    }
	    aa.reverse();
	    bb.reverse();
	    int cur = 0;
	    for(int i = 0; i < aa.length(); ++i)
	    {
		    if(i < bb.length())
		    {
			    cur += bb.charAt(i) - '0';
		    }
		    cur += (aa.charAt(i) - '0');
		    if((cur % 2) == 0)
		    {
		    	aa.setCharAt(i, '0');
		    }
		    else
		    {
		    	aa.setCharAt(i, '1');
		    }
	//	    System.out.println(i + " : " + cur);
		    cur = cur / 2;
	    }
	    if(cur % 2 == 1)
	    {
		    aa.append('1');
	    }
	    aa.reverse();
	    return aa.toString();
    }
    public static void main(String args[])
    {
	    System.out.println(addBinary("1", "111"));
    }
}
