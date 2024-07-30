class PalindromeChecker {
private:
    string processedString;
    vector<int> palindromicLengths;

    string preprocessString(const string& s) {
        string result = "#";
        for (char c : s) {
            result += c;
            result += "#";
        }
        return result;
    }

    void manacher() {
        int n = processedString.length();
        palindromicLengths.resize(n);

        int center = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            int mirror = 2 * center - i;

            if (i < right) {
                palindromicLengths[i] = min(right - i, palindromicLengths[mirror]);
            }

            // Expand around the current character
            int leftBound = i - (palindromicLengths[i] + 1);
            int rightBound = i + (palindromicLengths[i] + 1);
            while (leftBound >= 0 && rightBound < n && processedString[leftBound] == processedString[rightBound]) {
                palindromicLengths[i]++;
                leftBound--;
                rightBound++;
            }

            // Adjust center and right boundaries
            if (i + palindromicLengths[i] > right) {
                center = i;
                right = i + palindromicLengths[i];
            }
        }
    }

public:
    PalindromeChecker(const string& s) {
        processedString = preprocessString(s);
        manacher();
    }

    bool isPalindrome(int l, int r) {
        int n = processedString.size();
        if (l < 0 || r >= n || l > r) {
            return false; // Invalid range
        }
        int len = r - l + 1;
        int processedLeft = 2 * l + 1;
        int processedRight = 2 * r + 1;
        int processedCenter = (processedLeft + processedRight) / 2;
        int palindromicLength = palindromicLengths[processedCenter];

        return len <= palindromicLength;
    }
};

