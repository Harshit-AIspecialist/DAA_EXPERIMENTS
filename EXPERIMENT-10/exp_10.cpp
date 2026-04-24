class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> dp(m+ 1, 0);  
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return (int)dp[m];
    }
    // Time Complexity: O(n * m)
    // Outer loop runs n times
    // Inner loop runs m times
    // Space Complexity: O(m)
    // Only using a 1D DP array of size (m + 1)
};
