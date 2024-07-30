public class A {

    public static boolean isSubseq(String a, String b) {
        int i = 0;
        for (char ch : b.toCharArray()) {
            if (i == a.length()) {
                return true;
            }
            if (a.charAt(i) == ch) {
                ++i;
            }
        }
        return (i == a.length());
    }

    public static String getValidWord(String s, String[] dictionary) {
        String res = "";
        for (String word : dictionary) {
            if (isSubseq(word, s)) {
                if (res.isEmpty() || res.compareTo(word) > 0) {
                    res = word;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String s = "abc";
        String[] dictionary = {"a", "ab", "abc", "ac", "b", "bc"};

        String validWord = getValidWord(s, dictionary);
        System.out.println("Valid word: " + validWord);
    }
}

