class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        
        int totalSum = 0;
        for (int x : arr) totalSum += x;
        
        vector<bool> dp(totalSum + 1, false);
        dp[0] = true; 
        
        for (int num : arr) {
            
            for (int j = totalSum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        int mini = INT_MAX;
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[s1]) {
                int diff = totalSum - 2 * s1;
                mini = min(mini, diff);
            }
        }
        
        return mini;
    }
    //Time complexity: O(n*sum) where n is the length of input array, and sum is sum of all elements of the array
    //Space complexity: O(n*sum)
};
